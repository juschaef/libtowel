/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/24 18:39:34 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_opt.h>
#include <stdlib.h>
#include <twl_arr.h>
#include <twl_xstring.h>

static void parse_single_arg(char *arg, t_twl_dict *opts)
{
	char *opt_key;

	while (*arg)
	{
		opt_key = twl_strnew(1);
		*opt_key = *arg;
		twl_dict_add(opts, opt_key, NULL);
		arg++;
	}
}

static void parse_argv(char **arr_opts, t_twl_dict *opts)
{
	while (*arr_opts)
	{
		if (**arr_opts != '-')
			break ;
		parse_single_arg(++(*arr_opts), opts);
		arr_opts++;
	}
}

t_twl_opt	*twl_opt_new(char **argv)
{
	t_twl_opt *twl_opt;

	twl_opt = malloc(sizeof(t_twl_opt));
	twl_opt->cmd = twl_strdup(argv[0]);
	argv++;
	twl_opt->opts = twl_dict_new();
	parse_argv(argv, twl_opt->opts);
	return (twl_opt);
}
