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

#include <unistd.h>

#include "twl_xstdlib.h"
#include "twl_lst.h"

#include "twl_malloc/zone_mgr.h"
#include "twl_malloc/zone.h"
#include "twl_malloc/smem.h"
#include "twl_malloc/utils.h"

t_zone_mgr			*zone_mgr_new(char *name)
{
	t_zone_mgr		*zone_mgr;
	t_lst			*zones;

	zones = twl_lst_new();
	if (!zones)
		return (NULL);
	zone_mgr = smem_get(STATIC_MEM_ZONE_MGR);
	if (!zone_mgr)
		return (NULL);
	zone_mgr->name = name;
	zone_mgr->zones = zones;
	zone_mgr->size = get_zone_size_by_name(name);
	return (zone_mgr);
}
