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

/*
** malloc_log(zone_mgr, malloc_addr);
*/
void				*zone_mgr_malloc(t_zone_mgr *zone_mgr, size_t size)
{
	t_zone			*zone;
	void			*malloc_addr;

	if (!zone_mgr)
		return (NULL);
	zone = zone_get_zone(zone_mgr, size);
	if (!zone)
		return (NULL);
	malloc_addr = zone_malloc(zone, size);
	(void)malloc_log;
	return (malloc_addr);
}
