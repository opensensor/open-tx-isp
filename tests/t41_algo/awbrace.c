/* awbrace: device-side client for the T41 custom AWB library ioctls (Lu-Fi/openimp#195), run on a camera (or QEMU guest) that has the
 * open-tx-isp T41 module loaded and the streamer running (AWB frames flow).  It talks to /dev/tx-isp directly, like libimp's worker thread.
 *   awbrace basic        argument errors, get/set/close without a library, double open, copy of the info block
 *   awbrace restore      baseline gains -> manual 2x/0.5x via the result ioctl -> close -> the automatic white balance is back
 *   awbrace closerace N  N rounds: open, three threads in get, close at a random moment; every thread must leave
 *   awbrace crash        a child registers a library, sets manual gains and is killed (no close, also while a worker thread sleeps in get): the release hook must unregister
 *   awbrace reopen N     N times open / 5 gets / close
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
#define GET 0xc0045423U
#define SET 0xc0045424U
#define OPEN 0xc0045425U
#define CLOSE 0xc0045426U
#define AEOPEN 0xc004541dU
static int fails;
static uint32_t cl(uint32_t v) { return v < 0x200 ? 0x200 : v > 0x1800 ? 0x1800 : v; }   /* the accepted result range (hardware gain, 1024 = 1.0) */
#define CHECK(c, ...) do { if (c) printf("ok   " __VA_ARGS__); else { printf("FAIL " __VA_ARGS__); fails++; } printf("\n"); fflush(stdout); } while (0)

/* AWB mode of the native AWB state (module parameter awb_diag_mode, updated at every published change): 0 automatic, 1 manual */
static int awbmode(void) { FILE *f = fopen("/sys/module/tx_isp_t41/parameters/awb_diag_mode", "r"); int v = -1; if (f) { if (fscanf(f, "%d", &v) != 1) v = -1; fclose(f); } return v; }
static int opendev(void) { int fd = open("/dev/tx-isp", O_RDWR); if (fd < 0) { perror("open /dev/tx-isp"); exit(2); } return fd; }
static int c_open(int fd, uint32_t *attr) { uint32_t b[7] = { COOKIE, 0 }; int r = ioctl(fd, OPEN, b); if (r == 0 && attr) memcpy(attr, b + 2, 20); return r ? -errno : 0; }
static int c_close(int fd) { uint32_t b[2] = { COOKIE, 0 }; return ioctl(fd, CLOSE, b) ? -errno : 0; }
static int c_get(int fd, uint32_t *b /* 683 words */) { memset(b, 0, 2732); b[0] = COOKIE; b[1] = 0; return ioctl(fd, GET, b) ? -errno : 0; }
static int c_set(int fd, uint32_t change, uint32_t r, uint32_t bl) { uint32_t b[6] = { COOKIE, 0, change, r, bl, 0 }; return ioctl(fd, SET, b) ? -errno : 0; }
static void wd(int s) { (void)s; printf("FAIL watchdog: a call did not return\n"); fflush(stdout); _exit(3); }

static void t_basic(void)
{
	static uint32_t b[700]; uint32_t attr[5] = { 0 }; int fd = opendev(), r;
	uint32_t bad[2] = { 0x1234, 0 }, ch1[2] = { COOKIE, 1 };

	CHECK(c_get(fd, b) == -EINVAL, "get without a registered library -> EINVAL (immediate)");
	CHECK(c_set(fd, 1, 600, 600) == -EINVAL, "set without a registered library -> EINVAL");
	CHECK(c_close(fd) == 0, "close without a registered library -> 0");
	CHECK(ioctl(fd, OPEN, bad) == -1 && errno == EPERM, "open with a wrong cookie -> EPERM");
	CHECK(ioctl(fd, OPEN, ch1) == -1 && errno == EINVAL, "open channel 1 -> EINVAL");
	CHECK(ioctl(fd, OPEN, NULL) == -1 && errno == EFAULT, "open NULL -> EFAULT");
	CHECK(ioctl(fd, 0xc0045420U, b) == -1 && errno == ENOTTY, "second-sensor handle 0xc0045420 -> ENOTTY (not in the stock module)");
	r = c_open(fd, attr);
	CHECK(r == 0, "open -> 0 (init attr en %u start %u/%u nodes %u/%u mode %u)", attr[0], attr[1], attr[2], ((uint8_t *)attr)[12], ((uint8_t *)attr)[13], attr[4]);
	CHECK(c_open(fd, NULL) == -EBUSY, "second open -> EBUSY");
	r = c_get(fd, b);
	CHECK(r == 0 && b[0] == COOKIE && b[2] && b[3], "get -> info block (cookie %x, cur gains r %u b %u, global %u %u %u %u)", b[0], b[2], b[3], b[4], b[5], b[6], b[7]);
	CHECK(c_set(fd, 0, 0, 0) == 0 && c_set(fd, 1, 0, 700) == 0 && c_set(fd, 1, 600, 0x1801) == 0 && c_set(fd, 1, 0x1ff, 700) == 0, "ignored results (change 0, zero / below 0x200 / above 0x1800) -> 0");
	CHECK(c_close(fd) == 0 && c_close(fd) == 0, "close, and a second close -> 0");
	CHECK(c_get(fd, b) == -EINVAL && c_set(fd, 1, 600, 600) == -EINVAL, "get / set after the close -> EINVAL");
	close(fd);
}

static void t_restore(void)
{
	static uint32_t b[700]; int fd = opendev(), i, ok = 0;
	uint32_t r0, b0, r1 = 0, b1 = 0, r2 = 0, b2 = 0; int m0, m1, m2;

	m0 = awbmode();
	CHECK(c_open(fd, NULL) == 0, "open (AWB mode %d before)", m0);
	for (i = 0; i < 5; i++) c_get(fd, b);
	r0 = b[2]; b0 = b[3];
	printf("     baseline (automatic) gains r %u b %u\n", r0, b0);
	c_set(fd, 1, cl(r0 * 2), cl(b0 / 2));
	for (i = 0; i < 6; i++) { c_get(fd, b); if (b[2] == cl(r0 * 2) && b[3] == cl(b0 / 2)) ok++; }
	r1 = b[2]; b1 = b[3]; m1 = awbmode();
	CHECK(m1 == 1, "AWB state is manual while the library answers (mode %d)", m1);
	CHECK(ok >= 4, "manual gains from the result are what the next info block reports (r %u b %u, %d/6)", r1, b1, ok);
	c_set(fd, 1, cl(r0 / 2), cl(b0 * 2));
	for (i = 0; i < 6; i++) c_get(fd, b);
	r2 = b[2]; b2 = b[3];
	CHECK(r2 == cl(r0 / 2) && b2 == cl(b0 * 2), "second result follows (r %u b %u)", r2, b2);
	CHECK(c_close(fd) == 0, "close");
	m2 = awbmode();
	CHECK(m2 == m0, "AWB mode after the close is the application's again (%d, before %d)", m2, m0);
	CHECK(c_open(fd, NULL) == 0, "open again");
	ok = 0;
	for (i = 0; i < 12; i++) { c_get(fd, b); if (b[2] != r2 || b[3] != b2) ok++; }
	printf("     after the close the gains are r %u b %u (library had r %u b %u, baseline r %u b %u)\n", b[2], b[3], r2, b2, r0, b0);
	CHECK(ok >= 1, "the application's white balance is back (gains no longer the library's)");
	c_close(fd);
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
		c_set(fd, 1, 600 + round, 700);
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
static void t_crashwait(void)
{
	/* a library process killed while its worker thread sleeps in get: the exit releases the file, the release unregisters the library */
	int fd = opendev(), i, ok = 0; pid_t p; int st; static uint32_t b[700];

	p = fork();
	if (p == 0) {
		int cfd = opendev(); pthread_t th;
		if (c_open(cfd, NULL)) _exit(10);
		pthread_create(&th, NULL, child_getter, &cfd);
		c_set(cfd, 1, 700, 900);
		usleep(300000);
		kill(getpid(), SIGKILL);
		_exit(11);
	}
	waitpid(p, &st, 0);
	CHECK(WIFSIGNALED(st), "child killed while its worker thread was in get");
	usleep(300000);
	CHECK(c_open(fd, NULL) == 0, "open after the kill -> 0 (the release unregistered the dead library)");
	for (i = 0; i < 12; i++) { c_get(fd, b); if (b[2] != 700 || b[3] != 900) ok++; }
	CHECK(ok >= 1, "the white balance of the dead library was given back (gains r %u b %u)", b[2], b[3]);
	c_close(fd);
	close(fd);
}

static void t_crash(void)
{
	static uint32_t b[700]; int fd = opendev(), i; pid_t p; int st;
	uint32_t r0, b0; int m0;

	m0 = awbmode();
	CHECK(c_open(fd, NULL) == 0, "open (parent), baseline");
	for (i = 0; i < 4; i++) c_get(fd, b);
	r0 = b[2]; b0 = b[3];
	CHECK(c_close(fd) == 0, "close (parent)");
	p = fork();
	if (p == 0) {
		int cfd = opendev(); uint32_t bb[700];
		if (c_open(cfd, NULL)) _exit(10);
		for (i = 0; i < 3; i++) c_get(cfd, bb);
		c_set(cfd, 1, cl(r0 * 2), cl(b0 / 2));
		for (i = 0; i < 3; i++) c_get(cfd, bb);
		kill(getpid(), SIGKILL);        /* the library "crashes": no close, the fd is released by the kernel */
		_exit(11);
	}
	waitpid(p, &st, 0);
	usleep(300000);
	{ int mm = awbmode(); CHECK(mm == m0, "AWB mode right after the kill is the application's again (%d, before %d)", mm, m0); }
	CHECK(WIFSIGNALED(st) && WTERMSIG(st) == SIGKILL, "child registered a library, set manual gains and was killed");
	usleep(300000);
	CHECK(c_open(fd, NULL) == 0, "open after the crash -> 0 (not EBUSY: the release unregistered the dead library)");
	{ int ok = 0; for (i = 0; i < 12; i++) { c_get(fd, b); if (b[2] != cl(r0 * 2) || b[3] != cl(b0 / 2)) ok++; } printf("     gains after the crash r %u b %u (baseline r %u b %u)\n", b[2], b[3], r0, b0);
	  CHECK(ok >= 1, "the white balance of the dead library was given back"); }
	c_close(fd);
	close(fd);
}

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
	if (argc < 2) { fprintf(stderr, "usage: awbrace basic|restore|closerace N|crash|reopen N\n"); return 2; }
	if (!strcmp(argv[1], "basic")) t_basic();
	else if (!strcmp(argv[1], "restore")) t_restore();
	else if (!strcmp(argv[1], "closerace")) t_closerace(argc > 2 ? atoi(argv[2]) : 100);
	else if (!strcmp(argv[1], "crash")) { t_crash(); t_crashwait(); }
	else if (!strcmp(argv[1], "reopen")) t_reopen(argc > 2 ? atoi(argv[2]) : 50);
	else return 2;
	printf("%s: %s\n", argv[1], fails ? "FAILED" : "all ok");
	return fails ? 1 : 0;
}
