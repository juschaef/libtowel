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

#include "twl_malloc/zone_mgr.h"
#include "twl_malloc/zone.h"
#include "twl_malloc/utils.h"

static bool			is_zone_have_enough_room(void *zone_, void *context)
{
	size_t			*size_ptr;
	char			*zone_name;
	size_t			total;
	t_zone			*zone;

	zone = zone_;
	TP2_UNPACK(context, size_ptr, zone_name);
	total = mseg_mgr_get_total_size(zone->msegs);
	return (total + *size_ptr <= zone->size);
	(void)zone_name;
}

static void			create_zone_if_none(t_zone_mgr *zone_mgr, size_t size)
{
	t_zone			*zone;

	if (!twl_lst_len(zone_mgr->zones))
	{
		zone = zone_new(size);
		if (!zone)
			return ;
		twl_lst_push(zone_mgr->zones, zone);
	}
}

static size_t		get_size(t_zone_mgr *zone_mgr, size_t size)
{
	if (zone_mgr->size == 0)
		return (size);
	return (zone_mgr->size);
}

t_zone				*zone_get_zone(t_zone_mgr *zone_mgr, size_t size)
{
	t_zone			*zone;
	t_tuple			context;

	context = TP2_NEW(&size, zone_mgr->name);
	create_zone_if_none(zone_mgr, get_size(zone_mgr, size));
	zone = twl_lst_find(zone_mgr->zones, is_zone_have_enough_room, &context);
	if (!zone)
	{
		zone = zone_new(get_size(zone_mgr, size));
		if (!zone)
			return (NULL);
		twl_lst_push(zone_mgr->zones, zone);
	}
	return (zone);
}
