#ifndef VLQ_INTERNAL_H
#define VLQ_INTERNAL_H

#include "ft_vlq.h"

#define GET_LAST_SHIFT(type) ((type) == VLQ_TYPE_UNSIGNED ? 63 : 62) // 63 for unsigned, 62 for signed

#define NEG 1ULL
#define POS (uint64_t) !NEG
#define IRRELEVANT_SIGN ((uint8_t)-1)
#define LAST 0ULL
#define NOT_LAST ((uint64_t)!LAST)

void __vlq_set_sign(vlq *v, uint64_t sign);
void __vlq_set_last(vlq *v, size_t index, uint64_t last);
void __vlq_set_value(vlq *v, size_t index, uint64_t value);
uint8_t __vlq_get_sign(const vlq *v);
uint8_t __vlq_get_last(const vlq *v, size_t index);
uint64_t __vlq_get_value(const vlq *v, size_t index);

size_t __vlq_get_size(const vlq *v);

#endif
