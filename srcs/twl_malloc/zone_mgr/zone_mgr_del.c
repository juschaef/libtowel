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

#include <stdlib.h>

#include "twl_xstdlib.h"
#include "twl_lst.h"

#include "twl_malloc/zone_mgr.h"
#include "twl_malloc/zone.h"

void				zone_mgr_del(t_zone_mgr *zone_mgr)
{
	twl_lst_del(zone_mgr->zones, zone_del);
	(void)free;
}
