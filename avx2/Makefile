CC = /usr/bin/gcc
CFLAGS = -Wall -g -O3 -mavx2 -no-pie

TESTS = test/test_horst \
		test/test_sign \
		test/test_wots \

.PHONY: clean test

tests: $(TESTS)

test: $(TESTS:=.exec)

test/test_horst: crypto_stream_chacha12.c chacha.S prg.c consts.c hash_2n_n_mask_8x.s transpose8x.s loop_hash_2n_n_mask_8x.s hash_2n_n_8x.s hash_n_n_8x.s horst.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c test/test_horst.c api.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha.S prg.c consts.c hash_2n_n_mask_8x.s transpose8x.s loop_hash_2n_n_mask_8x.s hash_2n_n_8x.s hash_n_n_8x.s horst.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c cpucycles.c test/test_horst.c -o $@

test/test_wots: crypto_stream_chacha12.c chacha.S prg.c wots.c consts.c genfullchain8x.s hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c transpose8x.s loop_hash_2n_n_mask_8x.s randombytes.c test/test_wots.c api.h hash.h randombytes.h params.h cpucycles.h cpucycles.c hash_n_n_8x.s
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha.S prg.c wots.c consts.c genfullchain8x.s hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c transpose8x.s loop_hash_2n_n_mask_8x.s randombytes.c cpucycles.c hash_n_n_8x.s test/test_wots.c -o $@

test/speed: hash_2n_n_8x_notrans.s hash_n_n_8x_notrans.s crypto_stream_chacha12.c chacha.S prg.c consts.c hash_2n_n_mask_8x.s hash_2n_n_8x.s hash_n_n_8x.s horst.c horst.h wots.c transpose8x.s loop_hash_2n_n_mask_8x.s genfullchain8x.s sign.c zerobytes.c zerobytes.h hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c test/speed.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) hash_2n_n_8x_notrans.s hash_n_n_8x_notrans.s crypto_stream_chacha12.c chacha.S prg.c consts.c hash_2n_n_mask_8x.s hash_2n_n_8x.s hash_n_n_8x.s horst.c wots.c transpose8x.s loop_hash_2n_n_mask_8x.s genfullchain8x.s sign.c zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c cpucycles.c randombytes.c test/speed.c -o $@

test/test_sign: crypto_stream_chacha12.c chacha.S prg.c consts.c hash_2n_n_mask_8x.s hash_2n_n_8x.s hash_n_n_8x.s horst.c horst.h wots.c genfullchain8x.s transpose8x.s loop_hash_2n_n_mask_8x.s sign.c zerobytes.c zerobytes.h hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c randombytes.c test/test_sign.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha.S prg.c consts.c hash_2n_n_mask_8x.s hash_2n_n_8x.s hash_n_n_8x.s horst.c wots.c genfullchain8x.s transpose8x.s loop_hash_2n_n_mask_8x.s sign.c zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c cpucycles.c randombytes.c test/test_sign.c -o $@

test/gen_testvectors: crypto_stream_chacha12.c chacha.S prg.c consts.c hash_2n_n_mask_8x.s hash_2n_n_8x.s hash_n_n_8x.s horst.c horst.h wots.c genfullchain8x.s transpose8x.s loop_hash_2n_n_mask_8x.s sign.c zerobytes.c zerobytes.h hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c test/gen_testvectors.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) crypto_stream_chacha12.c chacha.S prg.c consts.c hash_2n_n_mask_8x.s hash_2n_n_8x.s hash_n_n_8x.s horst.c wots.c genfullchain8x.s transpose8x.s loop_hash_2n_n_mask_8x.s sign.c zerobytes.c hash.c crypto_hash_blake512.c crypto_hash_blake256.c permute.c cpucycles.c test/gen_testvectors.c -o $@

test/%.exec: test/%
	@$<

clean:
	-$(RM) $(TESTS)
