#include "crypto_stream_chacha12.h"
#include <stddef.h>

#include "chacha12/e/ref/e/ecrypt-sync.h"

int crypto_stream_chacha12(unsigned char *out, unsigned long long outlen, const unsigned char *n, const unsigned char *k) 
{
    ECRYPT_ctx x;
    ECRYPT_keysetup(&x, k, crypto_stream_chacha12_KEYBYTES*8, crypto_stream_chacha12_NONCEBYTES*8); // nonce size is not used?
    ECRYPT_ivsetup(&x, n);
    ECRYPT_keystream_bytes(&x, out, outlen);
    return 0;
}