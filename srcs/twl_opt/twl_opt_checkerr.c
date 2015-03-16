/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_checkerr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/03/01 17:10:21 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "twl_opt.h"
#include "twl_opt_elem.h"
#include "twl_stdio.h"

static bool			find_fn(void *opt_elem_, void *valid_opts_)
{
	t_opt_elem		*opt_elem;
	char			*valid_opts;

	opt_elem = opt_elem_;
	valid_opts = valid_opts_;
	if (!twl_strchr(valid_opts, *opt_elem->key))
		return (true);
	return (false);
}

char				*twl_opt_checkerr(t_opt *twl_opt, char *valid_opts)
{
	t_opt_elem		*opt_elem;

	opt_elem = twl_lst_find(twl_opt->opts, find_fn, valid_opts);
	if (opt_elem)
		return (opt_elem->key);
	return (NULL);
}
