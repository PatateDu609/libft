#include "libft.h"
#include "ft_vlq.h"
#include "vlq_internal.h"

vlq *vlq_new(enum e_vlq_type type)
{
	vlq *new;

	if (!(new = ft_calloc(1, sizeof(vlq))))
		return (NULL);
	vlq init = {.type = type, .value = NULL};
	ft_memcpy(new, &init, sizeof(vlq));
	new->value = ft_calloc(1, sizeof(uint64_t));
	__vlq_set_last(new, 0, LAST);
	__vlq_set_sign(new, POS);
	__vlq_set_value(new, 0, 0);
	return (new);
}

void vlq_resize(vlq *v, size_t size)
{
	size_t cur = __vlq_get_size(v);
	if (size <= cur)
		return;
	t_vlq_part *new = malloc(size * sizeof(t_vlq_part));
	if (!new)
		return;
	uint8_t sign = __vlq_get_sign(v);
	ft_memcpy(new, v->value + 1, cur * sizeof(t_vlq_part));
	free(v->value);
	v->value = new;
	if (v->type == VLQ_TYPE_SIGNED) // Shift last bit over sign
	{
		v->value[1] &= ~(1ULL << 62);
		__vlq_set_last(v, 1, NOT_LAST);
	}
	__vlq_set_sign(v, sign);
	__vlq_set_last(v, cur - 1, NOT_LAST);
	__vlq_set_last(v, size - 1, LAST);
}

vlq *vlq_dup(const vlq *a)
{
	vlq *new;

	if (!(new = ft_calloc(1, sizeof(vlq))))
		return (NULL);
	ft_memcpy(new, a, sizeof(vlq));
	return (new);
}

void vlq_free(vlq *a)
{
	if (!a)
		return;
	free(a->value);
	free(a);
}
