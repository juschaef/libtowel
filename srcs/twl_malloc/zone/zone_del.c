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

#include <stdio.h>
#include "twl_stdlib.h"
#include <sys/mman.h>

#include "twl_malloc/zone.h"
#include "twl_malloc/mseg.h"

#include "twl_xstdio.h"

void				zone_del(t_zone *zone)
{
	twl_lst_del(zone->msegs, mseg_del);
	munmap(zone->addr, zone->size);
}
