#include "crypto_stream_chacha12.h"
#include <stddef.h>

extern void chacha_avx2(const unsigned char *k, const unsigned char *n, const unsigned char *in, unsigned char *out, size_t inlen, size_t rounds);

int crypto_stream_chacha12(unsigned char *out, unsigned long long outlen, const unsigned char *n, const unsigned char *k) 
{
	chacha_avx2(k, n, NULL, out, (size_t)outlen, 12);
	return 0;
}
