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

#include "twl_malloc.h"

#include "twl_malloc/mseg_mgr.h"
#include "twl_malloc/zone_mgr.h"

t_mseg				*gmem_get_mseg_by_addr(void *addr)
{
	t_mseg			*mseg;
	t_gmem			*gmem;

	gmem = gmem_singleton();
	if (!gmem)
		return (NULL);
	mseg = zone_mgr_get_mseg_by_addr(gmem->zone_mgr_tiny, addr);
	if (!mseg)
		mseg = zone_mgr_get_mseg_by_addr(gmem->zone_mgr_small, addr);
	if (!mseg)
		mseg = zone_mgr_get_mseg_by_addr(gmem->zone_mgr_large, addr);
	return (mseg);
}
