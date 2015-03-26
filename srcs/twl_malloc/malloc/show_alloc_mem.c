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

#include "twl_stdio.h"

#include "twl_malloc.h"
#include "twl_malloc/gmem.h"
#include "twl_malloc/zone.h"
#include "twl_malloc/zone_mgr.h"
#include "twl_malloc/mseg.h"
#include "twl_malloc/utils.h"

static void			print_mseg(void *mseg_, void *context)
{
	t_mseg			*mseg;

	mseg = mseg_;
	twl_putstr("0x");
	twl_llutobasestr_print((unsigned long long)mseg->addr, 16);
	twl_putstr(" - 0x");
	twl_llutobasestr_print((unsigned long long)mseg->addr + mseg->size, 16);
	twl_putstr(" : ");
	twl_putnbr_size_t_fd(mseg->size, 1);
	twl_putstr(" bytes\n");
	(void)context;
}

static	void		print_zone(void *zone_, int index, void *name)
{
	t_zone			*zone;

	zone = zone_;
	twl_putstr("ZONE ");
	twl_putnbr(index);
	twl_putstr(": 0x");
	twl_llutobasestr_print((unsigned long long)zone->addr, 16);
	print_zone_progress(zone);
	twl_putstr("\n");
	twl_lst_iter(zone->msegs, print_mseg, NULL);
	(void)name;
	(void)index;
}

static	void		print_zone_manager(t_zone_mgr *zone_mgr)
{
	print_colored_by_name(zone_mgr->name);
	twl_putstr("\n");
	twl_lst_iteri(zone_mgr->zones, print_zone, zone_mgr->name);
}

void				twl_show_alloc_mem(void)
{
	static pthread_mutex_t	show_alloc_mem_mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&show_alloc_mem_mutex);
	print_zone_manager(gmem_singleton()->zone_mgr_tiny);
	print_zone_manager(gmem_singleton()->zone_mgr_small);
	print_zone_manager(gmem_singleton()->zone_mgr_large);
	pthread_mutex_unlock(&show_alloc_mem_mutex);
}
