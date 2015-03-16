/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/26 17:04:03 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_opt.h"
#include "twl_arr.h"
#include "twl_xstring.h"
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

static void			push_non_opt_to_lst(void *non_opt_arg,
														void *non_opt_arg_lst_)
{
	t_lst			*non_opt_arg_lst;

	non_opt_arg_lst = non_opt_arg_lst_;
	twl_lst_push(non_opt_arg_lst, twl_strdup(non_opt_arg));
}

static void			parse_argv(char **arr_opts, t_opt *twl_opt)
{
	char			*opt;

	while (*arr_opts)
	{
		if (**arr_opts != '-')
			break ;
		if (twl_strequ(*arr_opts, "--"))
		{
			arr_opts++;
			break ;
		}
		opt = *arr_opts;
		parse_single_arg(opt + 1, twl_opt->opts);
		arr_opts++;
	}
	twl_opt->non_opt_args = twl_lst_new();
	twl_arr_iter(arr_opts, push_non_opt_to_lst, twl_opt->non_opt_args);
}

t_opt				*twl_opt_new(char **argv)
{
	t_opt			*twl_opt;

	twl_opt = malloc(sizeof(t_opt));
	twl_opt->cmd = twl_strdup(argv[0]);
	twl_opt->opts = twl_lst_new();
	parse_argv(argv + 1, twl_opt);
	return (twl_opt);
}
