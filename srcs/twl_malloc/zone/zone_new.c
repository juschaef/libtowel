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

#include <sys/mman.h>

#include "twl_xstdlib.h"
#include "twl_string.h"

#include "twl_malloc/zone.h"
#include "twl_malloc/mseg_mgr.h"
#include "twl_malloc/smem.h"

#include <stdio.h>

#include <sys/mman.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

t_zone				*zone_new(size_t size)
{
	t_zone			*zone;
	void			*addr;

	zone = smem_get(STATIC_MEM_ZONE);
	if (!zone)
		return (NULL);
	addr = mmap(0, size, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!addr)
		return (NULL);
	zone->msegs = mseg_mgr_new();
	zone->size = size;
	zone->addr = addr;
	return (zone);
}
