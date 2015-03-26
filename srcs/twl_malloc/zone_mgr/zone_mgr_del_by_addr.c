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
#include "twl_xstring.h"
#include "twl_lst.h"

#include "twl_malloc.h"
#include "twl_malloc/mseg.h"
#include "twl_malloc/zone_mgr.h"

static bool			filter_by_addr_fn(void *mseg_, void *addr)
{
	t_mseg			*mseg;

	mseg = mseg_;
	return (mseg->addr != addr);
}

static void			del_by_addr_iter_zone_fn(void *zone_, void *addr)
{
	t_zone			*zone;

	zone = zone_;
	twl_lst_filter(zone->msegs, filter_by_addr_fn, addr, mseg_del_void);
}

void				zone_mgr_del_by_addr(t_zone_mgr *zone_mgr, void *addr)
{
	twl_lst_iter(zone_mgr->zones, del_by_addr_iter_zone_fn, addr);
	if (twl_strequ(zone_mgr->name, ZONE_NAME_LARGE))
		zone_mgr_del_empty_zones(zone_mgr);
}
