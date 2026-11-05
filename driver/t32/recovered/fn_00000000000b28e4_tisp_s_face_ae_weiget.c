/* T32 OEM 0xb28e4: tisp_s_face_ae_weiget; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_ae_api_set_face_ae_tune_params();
int32_t tisp_s_face_ae_weiget(char arg1, int32_t *arg2)
{
	return tisp_ae_api_set_face_ae_tune_params((unsigned char)arg1,
						   arg2,
						   &arg2[1],
						   &arg2[2]);
}
