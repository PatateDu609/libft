#include "libft.h"
#include <inttypes.h>

#ifdef SYS_ENDIAN
#include <arpa/inet.h>
#else

static uint8_t check_endian()
{
	int x = 0x01234567;

	return *(uint8_t *)&x == 0x67;
}

#endif

uint16_t ft_htons(uint16_t hostshort)
{
#ifdef SYS_ENDIAN
	return htons(hostshort);
#else
	return check_endian() ? (hostshort & 0xFF00) >> 8 | (hostshort & 0x00FF) << 8 : hostshort;
#endif
}

uint32_t ft_htonl(uint32_t hostlong)
{
#ifdef SYS_ENDIAN
	return htons(hostlong);
#else
	if (check_endian())
		return hostlong >> 24 |
			   (hostlong & 0xFF0000) >> 8 |
			   (hostlong & 0x00FF00) << 8 |
			   hostlong << 24;
	return hostlong;
#endif
}

uint16_t ft_ntohs(uint16_t netshort)
{
#ifdef SYS_ENDIAN
	return htons(netshort);
#else
	return ft_htons(netshort);
#endif
}

uint32_t ft_ntohl(uint32_t netlong)
{
#ifdef SYS_ENDIAN
	return htons(netlong);
#else
	return ft_htonl(netlong);
#endif
}
