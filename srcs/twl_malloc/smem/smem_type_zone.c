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

#define MAX_ZONE 10 * 1000

void				*static_mem_zone(void)
{
	static t_zone	zone[MAX_ZONE];
	static int		zone_idx = 0;

	if (zone_idx == 0)
		twl_bzero(zone, sizeof(t_zone) * MAX_ZONE);
	if (zone_idx >= MAX_ZONE)
	{
		smem_err_overflow("static_mem_zone");
		return (NULL);
	}
	return (&(zone[zone_idx++]));
}
