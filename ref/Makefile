CC = /usr/bin/gcc
CFLAGS = -Wall -g -O3

TESTS = test/test_horst \
		test/test_sign \
		test/test_wots \

.PHONY: clean test

tests: $(TESTS)

test: $(TESTS:=.exec)

test/test_horst: crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c horst.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c test/test_horst.c api.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c horst.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c cpucycles.c test/test_horst.c -o $@

test/test_wots: crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c wots.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c test/test_wots.c api.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c wots.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c cpucycles.c test/test_wots.c -o $@

test/speed: crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c horst.c horst.h wots.c sign.c zerobytes.h zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c test/speed.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c horst.c wots.c sign.c zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c cpucycles.c randombytes.c test/speed.c -o $@

test/test_sign: crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c horst.c horst.h wots.c sign.c zerobytes.h zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c test/test_sign.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c horst.c wots.c sign.c zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c cpucycles.c randombytes.c test/test_sign.c -o $@

test/gen_testvectors: crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c horst.c horst.h wots.c sign.c zerobytes.h zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c test/gen_testvectors.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha12/e/ref/e/chacha.c prg.c horst.c wots.c sign.c zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c cpucycles.c test/gen_testvectors.c -o $@

test/%.exec: test/%
	@$<

clean:
	-$(RM) $(TESTS)
