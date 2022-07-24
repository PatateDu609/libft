#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "ft_getopt.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"

#define program_name program_invocation_short_name

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
					dprintf(2, "%s: -%c: Options that need a value aren't mixable.\n", program_name, opts[j].short_name);
				else if ((!arg1 || !opts[j].check(arg1)))
					dprintf(2, "%s: -%c: %s\n", program_name, opts[j].short_name, opts[j].arg_help);
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

static int64_t manage_long_opt(t_option *opts, int nb_opts, char *arg)
{
	for (int i = 0; i < nb_opts; i++)
	{
		char *name = opts[i].name;
		if (!name) // If the option is a flag with no long name
			continue;
		if (ft_strncmp(arg, name, ft_strlen(name)))
			continue;

		char *equal = ft_strchr(arg, '=');
		if (opts[i].need_value)
		{
			char *value = equal ? equal + 1 : NULL;
			if (!value)
			{
				dprintf(2, "%s: %s: %s\n", program_name, name, opts[i].arg_help);
				exit(1);
			}
			if (!opts[i].check(value))
			{
				dprintf(2, "%s: %s: %s\n", program_name, name, opts[i].small_print);
				exit(1);
			}
			opts[i].value = value;
			return opts[i].flag;
		}
		if (equal)
		{
			dprintf(2, "%s: %s: Argument doesn't allow a value.\n", program_name, name);
			exit(1);
		}
		return opts[i].flag;
	}
	return -1;
}

int64_t get_option(t_option *options, int nb_opts, char *arg, char *arg1)
{
	if (arg[0] == '-' && arg[1] == '-')
		return manage_long_opt(options, nb_opts, arg + 2);
	else if (arg[0] == '-')
		return manage_short_opt(options, nb_opts, arg, arg1);
	return 0;
}
