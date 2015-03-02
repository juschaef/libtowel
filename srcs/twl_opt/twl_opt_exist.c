/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/28 18:29:41 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "twl_opt.h"
#include "twl_opt_elem.h"

bool find_opt(void *opt_elem_, void *opt_key)
{
	t_twl_opt_elem *opt_elem;

	opt_elem = opt_elem_;
	if (twl_strcmp(opt_elem->key, opt_key) == 0)
		return (true);
	return (false);
}

bool twl_opt_exist(t_twl_opt *twl_opt, char *opt_key)
{
	return (!!twl_lst_find(twl_opt->opts, find_opt, opt_key));
}
