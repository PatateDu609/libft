#include "../vlq_internal.h"

size_t __vlq_get_size(const vlq *v)
{
	size_t i;

	if (v->type == VLQ_TYPE_NONE)
		return (0);
	i = 0;
	while (!__vlq_get_last(v, i))
		i++;
	return (i + 1);
}
