#ifndef FT_GETOPT_H
#define FT_GETOPT_H

#include <stddef.h>
#include <stdlib.h>
#include <inttypes.h>

#ifndef __GLIBC__ // Work only on OSX and BSD systems
#define program_invocation_short_name getprogname()
#endif

#include "libft.h"

typedef struct s_option
{
	char short_name;
	char *name;
	char *description;
	uint64_t flag;

	int need_value;
	char *value;
	char *arg_help;
	char *small_print;
	int (*check)(char *);
} t_option;

typedef struct s_args
{
	char **args;
	uint64_t flags;
	int nb_opt;
	t_option *options;
} t_args;

int64_t get_option(t_option *options, int nb_opt, char *arg, char *arg1);
t_option *init_options(int *nb);
void print_flags(uint64_t flags, t_option *options);
t_args *parse_args(int ac, char **av);
void print_help(t_args *args);
void free_args(t_args *args);

#endif
