#include "../vlq_internal.h"

void __vlq_set_sign(vlq *v, uint64_t sign)
{
	if (v->type == VLQ_TYPE_NONE || v->type == VLQ_TYPE_UNSIGNED)
		return;
	v->value[0] = (v->value[0] & ~(1ULL << 63)) | (sign << 63);
}

void __vlq_set_last(vlq *v, size_t index, uint64_t last)
{
	int shift = index ? 63 : GET_LAST_SHIFT(v->type);
	uint64_t mask = ~(1ULL << shift);
	v->value[index] = (v->value[index] & mask) | (last << shift);
}

void __vlq_set_value(vlq *v, size_t index, uint64_t value)
{
	int shift = index ? 63 : GET_LAST_SHIFT(v->type);
	uint64_t m = (v->type == VLQ_TYPE_SIGNED && !index) ? 0b11 : 1;
	uint64_t mask = (m << shift);
	//* (1ULL << shift) is the mask for the value (keep the last bit and the sign bit if needed)
	v->value[index] = (v->value[index] & mask) | (value);
}

uint8_t __vlq_get_sign(const vlq *v)
{
	if (v->type == VLQ_TYPE_NONE || v->type == VLQ_TYPE_UNSIGNED)
		return (IRRELEVANT_SIGN);
	return ((v->value[0] >> 63) & 1);
}

uint8_t __vlq_get_last(const vlq *v, size_t index)
{
	int shift = index ? 63 : GET_LAST_SHIFT(v->type);
	return (v->value[index] >> shift) == LAST;
}

uint64_t __vlq_get_value(const vlq *v, size_t index)
{
	int shift = (index ? 63 : GET_LAST_SHIFT(v->type));
	uint64_t m = (v->type == VLQ_TYPE_SIGNED && !index) ? 0b11 : 1;
	uint64_t mask = (m << shift);
	return (v->value[index] & ~mask);
}
