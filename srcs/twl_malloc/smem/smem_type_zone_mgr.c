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

#include "twl_malloc/gmem.h"
#include "twl_malloc/smem.h"

#define MAX_ZONE_MGR 100

void				*static_mem_zone_mgr(void)
{
	static t_zone_mgr		zone_mgr[MAX_ZONE_MGR];
	static int				zone_mgr_idx = 0;

	if (zone_mgr_idx >= MAX_ZONE_MGR)
	{
		smem_err_overflow("static_mem_zone");
		return (NULL);
	}
	return (&(zone_mgr[zone_mgr_idx++]));
}
