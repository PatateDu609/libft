#include "ft_vlq.h"
#include "vlq_internal.h"

#include <stdio.h>

static void vlq_add_unsigned(vlq *a, const vlq *b)
{
	size_t i;
	size_t size;
	uint64_t carry;

	size = __vlq_get_size(a);
	carry = 0;
	for (i = 0; i < size; i++)
	{
		uint64_t value = __vlq_get_value(a, i) + __vlq_get_value(b, i) + carry;
		int shift = i ? 63 : GET_LAST_SHIFT(a->type);
		uint64_t mask = ~(1ULL << shift);
		__vlq_set_value(a, i, value & mask);
		carry = value;
	}
	if (carry)
	{
		vlq_resize(a, size + 1);
		__vlq_set_value(a, size, carry);
	}
}

void vlq_add_ip(vlq *a, const vlq *b)
{
	if (a->type == VLQ_TYPE_NONE)
		return;
	if (a->type == VLQ_TYPE_UNSIGNED)
		vlq_add_unsigned(a, b);
	else
		fprintf(stderr, "vlq_add_ip: Not implemented for signed VLQ\n");
}

vlq *vlq_add(const vlq *a, const vlq *b)
{
	vlq *result = vlq_dup(a);

	if (!result)
		return (NULL);
	vlq_add_ip(result, b);
	return (result);
}
