/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 11:00:43 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_opt.h>
#include <stdlib.h>
#include <twl_arr.h>
#include <twl_xstring.h>
#include <twl_opt_elem.h>

static void parse_single_arg(char *arg, t_lst *opts)
{
	char opt_key[2];

	twl_bzero(opt_key, 2);
	while (*arg)
	{
		*opt_key = *arg;
		twl_lst_push(opts, twl_opt_elem_new(opt_key, NULL));
		arg++;
	}
}

static void parse_argv(char **arr_opts, t_twl_opt *twl_opt)
{
	while (*arr_opts)
	{
		if (**arr_opts != '-')
			break ;
		parse_single_arg(++(*arr_opts), twl_opt->opts);
		arr_opts++;
	}
	twl_opt->non_opt_args = twl_arr_to_lst(arr_opts);
}

t_twl_opt	*twl_opt_new(char **argv)
{
	t_twl_opt *twl_opt;

	twl_opt = malloc(sizeof(t_twl_opt));
	twl_opt->cmd = twl_strdup(argv[0]);
	argv++;
	twl_opt->opts = twl_lst_new();
	parse_argv(argv, twl_opt);
	return (twl_opt);
}
