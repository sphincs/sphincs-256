#include <stdio.h>
#include "../wots.h"
#include "../randombytes.h"
#include "../params.h"

int main()
{
unsigned char seed[SEED_BYTES];
unsigned char pk1[WOTS_L*HASH_BYTES];
unsigned char pk2[WOTS_L*HASH_BYTES];
unsigned char sig[WOTS_L*HASH_BYTES];
unsigned char mask[WOTS_W*HASH_BYTES];

  unsigned char msg[32];
  int i;

  randombytes(seed, SEED_BYTES);
  randombytes(mask, WOTS_W*HASH_BYTES);
  randombytes(msg,32);

  wots_pkgen(pk1, seed, mask);
  wots_sign(sig, msg, seed, mask);
  wots_verify(pk2, sig, msg, mask);

  for(i=0;i<WOTS_L*HASH_BYTES;i++)
    if(pk1[i] != pk2[i])
    {
      printf("fuck %d\n",i);
      return -1;
    }

  return 0;
}
