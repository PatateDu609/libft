#ifndef FT_MATH_H
#define FT_MATH_H

#include <inttypes.h>

// Typedef for a 128-bit signed and unsigned integer.
typedef __int128_t int128_t;
typedef __uint128_t uint128_t;

uint64_t ft_pow(int64_t nb, int power);

int128_t ft_get_int128(int64_t a, uint64_t b);
char *ft_get_int128_str(int128_t n, int base);
uint128_t ft_get_uint128(uint64_t a, uint64_t b);
char *ft_get_uint128_str(uint128_t n, int base);

int128_t ft_atoi128_base(char *str, int base);
uint128_t ft_atoui128_base(char *str, int base);

#define ft_atoi128(str) ft_atoi128_base(str, 10)
#define ft_atoui128(str) ft_atoui128_base(str, 10)

#endif
