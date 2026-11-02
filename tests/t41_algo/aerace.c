/* aerace: device-side client for the T41 custom AE library ioctls (release-hook extra), run on a camera that has the open-tx-isp T41 module
 * loaded and the streamer running (vendor AE statistics events flow).  It talks to /dev/tx-isp directly, like libimp's AE worker thread.
 *   aerace basic        get/set/close without a library, bad cookie/channel, double open, info block
 *   aerace closerace N  N rounds: open, three threads in get, close at a random moment; every thread must leave
 *   aerace crash        a child registers a library and is killed (no close; once idle, once with a worker thread sleeping in get): the release hook must
 *                       unregister it, the next client opens (before the extra: EBUSY, the stock behaviour) and gets frames
 *   aerace reopen N     N times open / 5 gets / close
 * Exit code 0 = all checks ok; every check prints "ok" / "FAIL". */
#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define COOKIE 0x336acU
#define GET 0xc004541bU
#define SET 0xc004541cU
#define OPEN 0xc004541dU
#define CLOSE 0xc004541eU
static int fails;
#define CHECK(c, ...) do { if (c) printf("ok   " __VA_ARGS__); else { printf("FAIL " __VA_ARGS__); fails++; } printf("\n"); fflush(stdout); } while (0)

static int opendev(void) { int fd = open("/dev/tx-isp", O_RDWR); if (fd < 0) { perror("open /dev/tx-isp"); exit(2); } return fd; }
static int c_open(int fd, uint32_t *attr) { uint32_t b[34] = { COOKIE, 0 }; int r = ioctl(fd, OPEN, b); if (r == 0 && attr) memcpy(attr, b, sizeof(b)); return r ? -errno : 0; }
static int c_close(int fd) { uint32_t b[2] = { COOKIE, 0 }; return ioctl(fd, CLOSE, b) ? -errno : 0; }
static int c_get(int fd, uint32_t *b /* 501 words */) { memset(b, 0, 2004); b[0] = COOKIE; b[1] = 0; return ioctl(fd, GET, b) ? -errno : 0; }
static int c_set(int fd) { uint32_t b[14] = { COOKIE, 0 }; return ioctl(fd, SET, b) ? -errno : 0; }   /* all-zero attribute: no change */
static void wd(int s) { (void)s; printf("FAIL watchdog: a call did not return\n"); fflush(stdout); _exit(3); }

static void t_basic(void)
{
	static uint32_t b[700]; uint32_t attr[34] = { 0 }; int fd = opendev(), r;
	uint32_t bad[34] = { 0x1234, 0 }, ch1[34] = { COOKIE, 1 };

	CHECK(c_get(fd, b) == -EINVAL, "get without a registered library -> EINVAL (immediate)");
	CHECK(c_set(fd) == -EINVAL, "set without a registered library -> EINVAL");
	CHECK(c_close(fd) == 0, "close without a registered library -> 0");
	CHECK(ioctl(fd, OPEN, bad) == -1 && errno == EPERM, "open with a wrong cookie -> EPERM");
	CHECK(ioctl(fd, OPEN, ch1) == -1 && errno == EINVAL, "open channel 1 -> EINVAL");
	CHECK(ioctl(fd, OPEN, NULL) == -1 && errno == EFAULT, "open NULL -> EFAULT");
	CHECK(ioctl(fd, 0xc0045420U, b) == -1 && errno == ENOTTY, "second-sensor handle 0xc0045420 -> ENOTTY");
	r = c_open(fd, attr);
	CHECK(r == 0, "open -> 0 (init attr it %u ag %u dg %u)", attr[3], attr[4], attr[5]);
	CHECK(c_open(fd, NULL) == -EBUSY, "second open -> EBUSY");
	r = c_get(fd, b);
	CHECK(r == 0, "get -> info block (%d)", r);
	CHECK(c_set(fd) == 0, "set (no change) -> 0");
	CHECK(c_close(fd) == 0 && c_close(fd) == 0, "close, and a second close -> 0");
	CHECK(c_get(fd, b) == -EINVAL && c_set(fd) == -EINVAL, "get / set after the close -> EINVAL");
	close(fd);
}

struct gt { int fd; volatile int ret, done; };
static void *getter(void *p)
{
	static __thread uint32_t b[700]; struct gt *g = p; int r;

	for (;;) { r = c_get(g->fd, b); if (r) break; }
	g->ret = r; g->done = 1;
	return NULL;
}
static void t_closerace(int n)
{
	int round, bad = 0, leaked = 0;

	srand(getpid());
	for (round = 0; round < n; round++) {
		int fd = opendev(), i; pthread_t th[3]; struct gt g[3]; struct timespec ts = { 0, (rand() % 20000) * 1000L };
		static uint32_t b[700];

		if (c_open(fd, NULL)) { bad++; close(fd); continue; }
		c_get(fd, b);
		for (i = 0; i < 3; i++) { g[i].fd = fd; g[i].ret = g[i].done = 0; pthread_create(&th[i], NULL, getter, &g[i]); }
		nanosleep(&ts, NULL);
		c_set(fd);
		if (c_close(fd) != 0) bad++;
		for (i = 0; i < 3; i++) {
			int w = 0; while (!g[i].done && w++ < 2000) usleep(1000);
			if (!g[i].done) { bad++; leaked++; } else { pthread_join(th[i], NULL); if (g[i].ret != -EINVAL) bad++; }
		}
		close(fd);
	}
	CHECK(bad == 0 && leaked == 0, "%d rounds of open + 3 getters + close at a random moment: every getter left with EINVAL (problems %d, stuck %d)", n, bad, leaked);
}

static void *child_getter(void *p) { uint32_t bb[700]; int fd = *(int *)p; while (c_get(fd, bb) == 0) ; return NULL; }
static void t_crashone(int withget)
{
	int fd = opendev(), i, ok = 0; pid_t p; int st; static uint32_t b[700];

	p = fork();
	if (p == 0) {
		int cfd = opendev(); pthread_t th; uint32_t bb[700];
		if (c_open(cfd, NULL)) _exit(10);
		if (withget) pthread_create(&th, NULL, child_getter, &cfd);
		else for (i = 0; i < 3; i++) c_get(cfd, bb);
		usleep(300000);
		kill(getpid(), SIGKILL);        /* no close: the kernel releases the fd */
		_exit(11);
	}
	waitpid(p, &st, 0);
	CHECK(WIFSIGNALED(st) && WTERMSIG(st) == SIGKILL, "child registered a library and was killed (%s)", withget ? "worker thread sleeping in get" : "idle");
	usleep(300000);
	i = c_open(fd, NULL);
	CHECK(i == 0, "open after the kill -> %d (0 = the release unregistered the dead library, -%d = EBUSY)", i, EBUSY);
	for (i = 0; i < 8; i++) if (c_get(fd, b) == 0) ok++;
	CHECK(ok >= 6, "the new library gets frames (%d/8)", ok);
	CHECK(c_close(fd) == 0, "close");
	close(fd);
}
static void t_crash(void) { t_crashone(0); t_crashone(1); }

static void t_reopen(int n)
{
	static uint32_t b[700]; int i, j, bad = 0;

	for (i = 0; i < n; i++) {
		int fd = opendev();
		if (c_open(fd, NULL)) bad++;
		for (j = 0; j < 5; j++) if (c_get(fd, b)) bad++;
		if (c_close(fd)) bad++;
		close(fd);
	}
	CHECK(bad == 0, "%d x open / 5 gets / close (problems %d)", n, bad);
}

int main(int argc, char **argv)
{
	signal(SIGALRM, wd); alarm(300);
	if (argc < 2) { fprintf(stderr, "usage: aerace basic|closerace N|crash|reopen N\n"); return 2; }
	if (!strcmp(argv[1], "basic")) t_basic();
	else if (!strcmp(argv[1], "closerace")) t_closerace(argc > 2 ? atoi(argv[2]) : 100);
	else if (!strcmp(argv[1], "crash")) t_crash();
	else if (!strcmp(argv[1], "reopen")) t_reopen(argc > 2 ? atoi(argv[2]) : 50);
	else return 2;
	printf("%s: %s\n", argv[1], fails ? "FAILED" : "all ok");
	return fails ? 1 : 0;
}
