/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/26 17:11:42 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_opt.h"
#include "twl_arr.h"
#include "twl_xstring.h"
#include "twl_opt_elem.h"

void	twl_opt_del(t_opt *twl_opt)
{
	twl_free(twl_opt->cmd);
	twl_lst_del(twl_opt->opts, twl_opt_elem_del);
	twl_lst_del(twl_opt->non_opt_args, free);
	twl_free(twl_opt);
}
