#include "ft_vlq.h"
#include "libft.h"

// static size_t vlq_strlen_unsigned(const vlq *a, int base)
// {
// 	size_t len = 0;
// 	size_t i;
// 	size_t uint64_len[] = {
// 		[2] = 64,
// 		[8] = 8 * 3,
// 		[10] = 8 * 3,
// 		[16] = 8 * 2};

// 	if (base < 2 || base > 16 || !uint64_len[base])
// 		return (0);

// 	for (i = 0; i < a->size; i++)
// 		len += uint64_len[base];
// 	return (len);
// }

// static size_t vlq_strlen(const vlq *a, int base)
// {
// 	size_t len = 0;
// 	size_t i;

// 	if (a->type == VLQ_TYPE_NONE)
// 		return (0);
// 	if (a->type == VLQ_TYPE_UNSIGNED)
// 		return (vlq_strlen_unsigned(a, base));
// 	else
// 		fprintf(stderr, "vlq_strlen: Not implemented for signed integers\n");
// 	return (len);
// }

// static char *vlq_to_str_unsigned(const vlq *a, int base)
// {
// 	char *str;
// 	size_t i;
// 	size_t len = vlq_strlen(a, base);

// 	if (!(str = (char *)ft_calloc(len + 1, sizeof(char))))
// 		return (NULL);
// 	for (i = 0; i < a->size; i++)
// 	{
// 		ft_itoa_base(a->value[i], base, str + (len - i * 3));
// 		len -= 3;
// 	}
// }

// char *vlq_to_str(const vlq *a, int base)
// {
// 	if (base != 2 && base != 8 && base != 10 && base != 16)
// 	{
// 		fprintf(stderr, "vlq_to_str: Invalid base %d\n", base);
// 		return (NULL);
// 	}

// 	if (!a)
// 		return (NULL);
// 	if (a->type == VLQ_TYPE_NONE)
// 		return (ft_strdup(""));
// 	if (a->type == VLQ_TYPE_UNSIGNED)
// 		return (vlq_to_str_unsigned(a, base));
// 	else
// 		fprintf(stderr, "vlq_to_str: Not implemented for signed integers\n");
// }
