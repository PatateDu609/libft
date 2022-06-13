#include "ft_math.h"

uint64_t ft_pow(int64_t nb, int power)
{
	uint64_t result = 1L;
	while (power)
	{
		if (power & 1)
			result *= nb;
		power >>= 1; // power /= 2
		nb *= nb;
	}
	return (result);
}
