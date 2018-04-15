#include <stdio.h>
#include <string.h>

#include "../crypto_sign.h"
#include "../api.h"

#define MLEN 3491

unsigned char sk[CRYPTO_SECRETKEYBYTES];
unsigned char pk[CRYPTO_PUBLICKEYBYTES];
unsigned char mi[MLEN];
unsigned char mo[MLEN+CRYPTO_BYTES];
unsigned char sm[MLEN+CRYPTO_BYTES];
unsigned long long smlen;
unsigned long long mlen;

int main()
{
  int r;
  unsigned long long i;
  FILE *urandom = fopen("/dev/urandom", "r");
  for(i=0;i<MLEN;i++) mi[i] = fgetc(urandom);

  printf("keypair\n");
  crypto_sign_keypair(pk, sk);
  // check masks in SK
  for(i=0;i<N_MASKS*HASH_BYTES;i++)
  {
    if(pk[i] != sk[SEED_BYTES+i]) printf("fuck %llu",i);
  }

  printf("sign\n");
  crypto_sign(sm, &smlen, mi, MLEN, sk);

  /* Test valid signature */
  printf("verify\n");
  r = crypto_sign_open(mo, &mlen, sm, smlen, pk);
  printf("%d\n", r);
  r = memcmp(mi,mo,MLEN);
  printf("%d\n", r);
  printf("%llu\n", MLEN-mlen);

  /* Test with modified message */
  sm[52] ^= 1;
  r = crypto_sign_open(mo, &mlen, sm, smlen, pk);
  printf("%d\n", r+1);
  r = memcmp(mi,mo,MLEN);
  printf("%d\n", (r!=0) - 1);
  printf("%llu\n", mlen+1);

  /* Test with modified signature */
  sm[260] ^= 1;
  sm[52] ^= 1;
  sm[2] ^= 1;
  r = crypto_sign_open(mo, &mlen, sm, smlen, pk);
  printf("%d\n", r+1);
  r = memcmp(mi,mo,MLEN);
  printf("%d\n", (r!=0) - 1);
  printf("%llu\n", mlen+1);

  
  printf("HORST_SIGBYTES:        %d\n",HORST_SIGBYTES);
  printf("WOTS_SIGBYTES:         %d\n",WOTS_SIGBYTES);
  printf("CRYPTO_BYTES:          %d\n",CRYPTO_BYTES);
  printf("CRYPTO_PUBLICKEYBYTES: %d\n",CRYPTO_PUBLICKEYBYTES);
  printf("CRYPTO_SECRETKEYBYTES: %d\n",CRYPTO_SECRETKEYBYTES);


  fclose(urandom);
  return 0;
}


