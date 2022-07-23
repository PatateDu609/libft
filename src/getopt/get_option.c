#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "ft_getopt.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static int64_t manage_short_opt(t_option *opts, int nb_opts, char *arg, char *arg1)
{
	int64_t flags = 0;

	for (int i = 1; arg[i]; i++)
	{
		uint8_t valid = 0;

		for (int j = 0; j < nb_opts; j++)
		{
			if (opts[j].short_name != arg[i])
				continue;
			if (opts[j].short_name == arg[i] && opts[j].need_value)
			{
				if (arg[i - 1] != '-' && arg[i + 1])
					dprintf(2, "%s: -%c: Options that need a value aren't mixable.\n", program_invocation_short_name, opts[j].short_name);
				else if ((!arg1 || !opts[j].check(arg1)))
					dprintf(2, "%s: -%c: %s\n", program_invocation_short_name, opts[j].short_name, opts[j].arg_help);
				if ((arg[i - 1] != '-' && arg[i + 1]) ||
					(!arg1 || !opts[j].check(arg1)))
					exit(1);
			}
			if (opts[j].need_value)
				opts[j].value = arg1;
			flags |= opts[j].flag;
			valid = 1;
			break;
		}
		if (!valid)
			return -1;
	}
	return flags;
}

// TODO: Add support for long options with value (must be an equal...).
static int64_t manage_long_opt(t_option *opts, int nb_opts, char *arg)
{
	for (int i = 0; i < nb_opts; i++)
	{
		if (opts[i].name && ft_strcmp(opts[i].name, arg + 2) == 0)
			return opts[i].flag;
	}
	return -1;
}

int64_t get_option(t_option *options, int nb_opts, char *arg, char *arg1)
{
	if (arg[0] == '-' && arg[1] == '-')
		return manage_long_opt(options, nb_opts, arg);
	else if (arg[0] == '-')
		return manage_short_opt(options, nb_opts, arg, arg1);
	return 0;
}
