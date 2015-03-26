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
#include "twl_malloc/zone.h"

static bool			filter_keep_non_empty_zones_fn(void *zone_, void *context)
{
	t_zone			*zone;

	zone = zone_;
	return (twl_lst_len(zone->msegs));
	(void)context;
}

void				zone_mgr_del_empty_zones(t_zone_mgr *zone_mgr)
{
	twl_lst_filter(zone_mgr->zones, filter_keep_non_empty_zones_fn,
														NULL, zone_del_void);
}
