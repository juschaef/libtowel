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
#include "twl_opt_elem.h"

void	twl_opt_del(t_opt *twl_opt)
{
	free(twl_opt->cmd);
	free(twl_opt->valid_opts);
	twl_lst_del(twl_opt->opts, twl_opt_elem_del);
	twl_lst_del(twl_opt->args, free);
	free(twl_opt);
}
