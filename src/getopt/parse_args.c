#include "ft_getopt.h"
#include <stdio.h>

int check_opt_value(char *arg, t_option *option, int nb_opt)
{
	if (option)
	{
		for (int i = 0; i < nb_opt; i++)
		{
			if (option[i].short_name == arg[1])
			{
				if (option[i].need_value)
					return 1;
				else
					return 0;
			}
		}
	}
	return -1;
}

static int get_size(int ac, char **av, int *first_arg, t_option *opt, int nb_opt)
{
	int size = 0;

	for (int i = 1; i < ac; i++)
	{
		if (!*first_arg && av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 0)
		{
			*first_arg = i + 1;
			continue;
		}
		else if (!*first_arg && av[i][0] == '-')
		{
			if (av[i][1] == '-')
				continue;
			int opt_value = check_opt_value(av[i], opt, nb_opt);
			if (opt && opt_value == 0)
				continue;
			else if (opt_value == 1)
			{
				i++;
				continue;
			}
			*first_arg = -1;
			return -1;
		}
		else if (!*first_arg)
			*first_arg = i;
		if (!*first_arg)
			continue;
		size++;
	}
	return size;
}

static uint8_t extract_args(int ac, char **av, t_args *args)
{
	int first_arg = 0;
	int size = get_size(ac, av, &first_arg, args->options, args->nb_opt);

	if (first_arg == -1)
	{
		print_help(args);
		return 0;
	}
	args->args = (char **)malloc(sizeof(char *) * (size + 1));
	if (!args->args)
		return 2;
	args->args[size] = NULL;

	if (size == 0)
		return 1;
	for (int i = first_arg; i < ac; i++)
		args->args[i - first_arg] = av[i];
	return (1);
}

static uint8_t extract_flags(int ac, char **av, t_args *args)
{
	if (!args->options)
		return 1;
	for (int i = 1; i < ac; i++)
	{
		int64_t opt = get_option(args->options, args->nb_opt, av[i], i + 1 < ac ? av[i + 1] : NULL);
		if (opt == -1)
		{
			print_help(args);
			return 0;
		}
		args->flags |= opt;
	}
	return 1;
}

static uint8_t check_options(t_args *args)
{
	int err = 0;
	if (!args->options)
		return 1;
	for (int i = 0; i < args->nb_opt; i++)
	{
		t_option *option = args->options + i;
		if (!option->short_name && !option->name)
		{
			dprintf(2, "An option (%d) needs a short name or a name\n", i);
			err = 1;
		}
		if (option->need_value)
		{
			if (!option->arg_help)
			{
				dprintf(2, "An option (%d) needs an argument help\n", i);
				err = 1;
			}
			if (!option->check)
			{
				dprintf(2, "An option (%d) need a checker function\n", i);
				err = 1;
			}
			if (!option->small_print)
			{
				dprintf(2, "An option (%d) needs a small print\n", i);
				err = 1;
			}
		}
	}

	if (err)
	{
		free(args->options);
		free(args->args);
	}
	return err;
}

t_args *parse_args(int ac, char **av)
{
	t_args *args;

	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return NULL;

	ft_memset(args, 0, sizeof(t_args));
	args->options = init_options(&args->nb_opt);
	if (check_options(args))
		exit(1);
	if (!extract_flags(ac, av, args))
	{
		free(args->options);
		free(args);
		return (void *)-1;
	}
	uint8_t ret = extract_args(ac, av, args);
	if (!ret)
	{
		free(args->options);
		free(args->args);
		free(args);
		return (void *)-1;
	}
	else if (ret == 2)
	{
		free(args->options);
		free(args);
		return NULL;
	}
	return args;
}

void free_args(t_args *args)
{
	free(args->options);
	free(args->args);
	free(args);
}
