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

#include "twl_xstdlib.h"
#include "twl_lst.h"

#include "twl_malloc/mseg.h"
#include "twl_malloc/zone_mgr.h"

static bool			find_by_addr_fn(void *mseg_, void *addr)
{
	t_mseg			*mseg;

	mseg = mseg_;
	return (mseg->addr == addr);
}

static bool			del_by_addr_iter_zone_fn(void *zone_, void *addr)
{
	t_zone			*zone;

	zone = zone_;
	return (!!twl_lst_find(zone->msegs, find_by_addr_fn, addr));
}

t_mseg				*zone_mgr_get_mseg_by_addr(t_zone_mgr *zone_mgr, void *addr)
{
	t_zone			*zone;
	t_mseg			*mseg;

	zone = twl_lst_find(zone_mgr->zones, del_by_addr_iter_zone_fn, addr);
	if (!zone)
		return (NULL);
	mseg = twl_lst_find(zone->msegs, find_by_addr_fn, addr);
	return (mseg);
}
