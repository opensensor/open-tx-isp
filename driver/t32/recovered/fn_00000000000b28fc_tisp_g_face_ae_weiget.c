/* T32 OEM 0xb28fc: tisp_g_face_ae_weiget; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_ae_api_get_face_ae_tune_params();
int32_t tisp_g_face_ae_weiget(char arg1, int32_t *arg2)
{
	return tisp_ae_api_get_face_ae_tune_params(arg1 & 0xff, arg2,
		&arg2[1], &arg2[2]);
}
