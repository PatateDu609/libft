#ifndef RANDOM_H
#define RANDOM_H

#include <inttypes.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>

#define ROTR32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

void init_pcg_state();
uint32_t pcg();
uint64_t pcg_64();
uint64_t pcg64_range(uint64_t min, uint64_t max);

#endif
