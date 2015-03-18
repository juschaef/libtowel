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

#define SMEM_LST_MAX 1 * 1000 * 1000

void				*twl_smem_type_lst(void)
{
	static t_lst	lst[SMEM_LST_MAX];
	static int		lst_idx = 0;

	if (lst_idx >= SMEM_LST_MAX)
	{
		twl_smem_err_overflow("static_mem_lst");
		return (NULL);
	}
	return (&(lst[lst_idx++]));
}
