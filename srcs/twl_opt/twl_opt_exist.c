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

#include <stdbool.h>
#include "twl_opt.h"
#include "twl_opt_elem.h"

bool	find_opt(void *opt_elem_, void *opt_key)
{
	t_opt_elem *opt_elem;

	opt_elem = opt_elem_;
	if (twl_strcmp(opt_elem->key, opt_key) == 0)
		return (true);
	return (false);
}

bool	twl_opt_exist(t_opt *twl_opt, char *opt_key)
{
	return (!!twl_lst_find(twl_opt->opts, find_opt, opt_key));
}
