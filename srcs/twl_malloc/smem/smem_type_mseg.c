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

#include "twl_malloc/mseg.h"
#include "twl_malloc/smem.h"

#define MAX_MSEG 1000 * 1000

void				*static_mem_mseg(void)
{
	static t_mseg		mseg[MAX_MSEG];
	static int			mseg_idx = 0;

	if (mseg_idx >= MAX_MSEG)
	{
		smem_err_overflow("static_mem_mseg");
		return (NULL);
	}
	return (&(mseg[mseg_idx++]));
}
