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

#include "twl_lst.h"
#include "twl_smem.h"

#define SMEM_LST_ELEM_MAX 10 * 1000

void				*twl_smem_type_lst_elem__(void)
{
	static t_lst_elem__	lst_elem__[SMEM_LST_ELEM_MAX];
	static int		lst_elem_idx = 0;

	if (lst_elem_idx == 0)
		twl_bzero(lst_elem__, sizeof(t_lst_elem__) * SMEM_LST_ELEM_MAX);
	if (lst_elem_idx >= SMEM_LST_ELEM_MAX)
	{
		twl_smem_err_overflow("static_mem_lst_elem__");
		return (NULL);
	}
	return (&(lst_elem__[lst_elem_idx++]));
}
