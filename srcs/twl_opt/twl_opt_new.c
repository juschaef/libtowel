/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_opt.h"
#include "twl_arr.h"
#include "twl_xstring.h"
#include "twl_string.h"
#include "twl_opt_elem.h"

static void			parse_single_arg(char *arg, t_lst *opts)
{
	char			opt_key[2];

	twl_bzero(opt_key, 2);
	while (*arg)
	{
		*opt_key = *arg;
		twl_lst_push(opts, twl_opt_elem_new(opt_key, NULL));
		arg++;
	}
}

static void			parse_opt_with_param(char *key, char *value, t_lst *opts)
{
	char			opt_key[2];

	twl_bzero(opt_key, 2);
	*opt_key = *key;
	twl_lst_push(opts, twl_opt_elem_new(opt_key, value));

}

static void			push_non_opt_to_lst(void *non_opt_arg,
														void *non_opt_arg_lst_)
{
	t_lst			*non_opt_arg_lst;

	non_opt_arg_lst = non_opt_arg_lst_;
	twl_lst_push(non_opt_arg_lst, twl_strdup(non_opt_arg));
}

static bool			is_valid_opt_with_param(char *opt_without_hyphen, char *valid_opts)
{
	char *found_opt;

	found_opt = twl_strchr(valid_opts, opt_without_hyphen[0]);
	if (found_opt && (found_opt[1] == ':'))
		return (true);
	return (false);
}

static char			**parse_arg_opt_and_return_non_opt_args(char **arr_opts, t_opt *opt, char *valid_opts)
{
	char			*opt_without_hyphen;
	char			*next_arg;
	int				i;

	i = 0;
	while (arr_opts[i])
	{
		if (*arr_opts[i] != '-')
			break ;
		opt_without_hyphen = arr_opts[i] + 1;
		if (twl_strequ(arr_opts[i], "--"))
		{
			i++;
			break ;
		}
		if (is_valid_opt_with_param(opt_without_hyphen, valid_opts))
		{
			next_arg = arr_opts[i + 1];
			parse_opt_with_param(opt_without_hyphen, next_arg, opt->opts);
			if (arr_opts[i + 1] != NULL)
				i += 2;
			else
				i++;
		}
		else
		{
			parse_single_arg(opt_without_hyphen, opt->opts);
			i++;
		}
	}
	return (&arr_opts[i]);
}

static void			parse_argv(char **arr_opts, t_opt *opt, char *valid_opts)
{
	char			**non_opt_args;

	non_opt_args = parse_arg_opt_and_return_non_opt_args(arr_opts, opt, valid_opts);
	opt->non_opt_args = twl_lst_new();
	if (non_opt_args)
		twl_arr_iter(non_opt_args, push_non_opt_to_lst, opt->non_opt_args);
}

t_opt				*twl_opt_new(char **argv, char *valid_opts)
{
	t_opt			*opt;
	char			**argv_without_cmd;

	opt = malloc(sizeof(t_opt));
	opt->cmd = twl_strdup(argv[0]);
	argv_without_cmd = argv + 1;
	opt->opts = twl_lst_new();
	opt->valid_opts = twl_strdup(valid_opts);
	parse_argv(argv_without_cmd, opt, valid_opts);
	return (opt);
}
