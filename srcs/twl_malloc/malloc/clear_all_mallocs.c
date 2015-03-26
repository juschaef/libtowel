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

#include <pthread.h>

#include "twl_malloc.h"

#include "twl_malloc/mseg.h"
#include "twl_malloc/mseg_mgr.h"
#include "twl_malloc/zone_mgr.h"

static void			clear_zone_msgs(void *zone_, void *context)
{
	t_zone *zone;

	zone = zone_;
	twl_lst_clear__(zone->msegs, mseg_del);
	(void)context;
}

static void			clear_zones(t_zone_mgr *zone_mgr)
{
	twl_lst_iter(zone_mgr->zones, clear_zone_msgs, NULL);
}

void				twl_clear_all_mallocs(void)
{
	clear_zones(gmem_singleton()->zone_mgr_tiny);
	clear_zones(gmem_singleton()->zone_mgr_small);
	clear_zones(gmem_singleton()->zone_mgr_large);
}
