#include <stdio.h>
#include "../horst.h"
#include "../randombytes.h"
#include "../params.h"

#define MLEN 417

int main()
{
unsigned char seed[SEED_BYTES];
unsigned char pk1[HASH_BYTES];
unsigned char pk2[HASH_BYTES];
unsigned char sig[HORST_SIGBYTES];
unsigned char masks[2*HORST_LOGT*HASH_BYTES];
unsigned long long sigbytes;
unsigned char msg_seed[MSGHASH_BYTES];

  unsigned char msg[MLEN];
  int i;

  randombytes(seed, SEED_BYTES);
  randombytes(msg,MLEN);
  randombytes(masks,N_MASKS*HASH_BYTES);
  randombytes(msg_seed, MSGHASH_BYTES);

  horst_sign(sig, pk1, &sigbytes, msg, MLEN, seed, masks, msg_seed);
  if(horst_verify(pk2, sig, msg, MLEN, masks, msg_seed))
    printf("fuck already here\n");

  for(i=0;i<HASH_BYTES;i++)
    if(pk1[i] != pk2[i])
      printf("fuck %d\n",i);

  return 0;
}
