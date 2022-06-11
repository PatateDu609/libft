#ifndef FT_VLQ_H
#define FT_VLQ_H

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

enum e_vlq_type
{
	VLQ_TYPE_NONE,	   // 0 (Unknown)
	VLQ_TYPE_UNSIGNED, // unsigned is the default
	VLQ_TYPE_SIGNED,   // signed integer (not implemented yet)
};

typedef uint64_t t_vlq_part;

/**
 * @brief The t_vlq struct
 *
 * @details
 * This struct is used to represent a vlq.
 * It is composed of a number of parts (vlq_part)
 * Each part is a 64 bits unsigned integer
 * The first part is the sign bit (only in the first part)
 * The second bit (or the first starting from the second part) specifies if this is the last part of the vlq
 * The rest of the bits are the value (62 bits in big endian), this is encoded in two complement
 * This gives us the following format
 * | sign bit | last bit | value | [| last bit | value |] [...]
 */
typedef struct s_vlq
{
	const enum e_vlq_type type;
	t_vlq_part *value;
} vlq;

vlq *vlq_new(enum e_vlq_type type);
void vlq_resize(vlq *a, size_t size);
void vlq_free(vlq *a);
vlq *vlq_dup(const vlq *a);

vlq *vlq_add(const vlq *a, const vlq *b);
void vlq_add_ip(vlq *a, const vlq *b);

vlq *vlq_sub(const vlq *a, const vlq *b);
void vlq_sub_ip(vlq *a, const vlq *b);

vlq *vlq_mul(const vlq *a, const vlq *b);
void vlq_mul_ip(vlq *a, const vlq *b);

vlq *vlq_div(const vlq *a, const vlq *b);
void vlq_div_ip(vlq *a, const vlq *b);

vlq *vlq_mod(const vlq *a, const vlq *b);
void vlq_mod_ip(vlq *a, const vlq *b);

char *vlq_to_str(const vlq *a, int base);
vlq *vlq_from_str(const char *str, int base);

vlq *vlq_shr(const vlq *a, size_t shift);
void vlq_shr_ip(vlq *a, size_t shift);

vlq *vlq_shl(const vlq *a, size_t shift);
void vlq_shl_ip(vlq *a, size_t shift);

vlq *vlq_and(const vlq *a, const vlq *b);
void vlq_and_ip(vlq *a, const vlq *b);

vlq *vlq_or(const vlq *a, const vlq *b);
void vlq_or_ip(vlq *a, const vlq *b);

vlq *vlq_xor(const vlq *a, const vlq *b);
void vlq_xor_ip(vlq *a, const vlq *b);

vlq *vlq_not(const vlq *a);
void vlq_not_ip(vlq *a);

vlq *vlq_rotr(const vlq *a, size_t shift);
void vlq_rotr_ip(vlq *a, size_t shift);

vlq *vlq_rotl(const vlq *a, size_t shift);
void vlq_rotl_ip(vlq *a, size_t shift);

#endif
