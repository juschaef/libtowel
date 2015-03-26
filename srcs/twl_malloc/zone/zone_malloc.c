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

#include "twl_xstdio.h"
#include "twl_lst.h"

#include "twl_malloc/zone.h"
#include "twl_malloc/mseg.h"
#include "twl_malloc/gmem.h"

static void			is_suitable_size_fn(void *mseg_, void *mseg_next_,
																void *context_)
{
	t_mseg							*mseg;
	t_mseg							*mseg_next;
	t_is_suitable_size_fn_context	*context;
	size_t							free_size;

	context = context_;
	mseg = mseg_;
	mseg_next = mseg_next_;
	if (!mseg_next)
		return ;
	free_size = (mseg_next->addr - mseg->addr) - mseg->size;
	if (context->mseg_prev)
		return ;
	if (free_size >= context->size)
		context->mseg_prev = mseg;
}

static int			get_suitable_pos(t_lst *msegs, size_t size)
{
	t_is_suitable_size_fn_context	context;

	context = (t_is_suitable_size_fn_context){.size = size, .mseg_prev = NULL};
	twl_lst_itern(msegs, is_suitable_size_fn, &context);
	if (!context.mseg_prev)
		return (-1);
	return (twl_lst_indexof(msegs, context.mseg_prev));
}

static t_mseg		*zone_get_next_suitable_malloc(t_zone *zone, size_t size)
{
	t_mseg			*mseg_prev;
	t_mseg			*a_mseg_new;
	void			*addr_new;
	int				index_of_prev;

	index_of_prev = get_suitable_pos(zone->msegs, size);
	mseg_prev = twl_lst_get(zone->msegs, index_of_prev);
	addr_new = (mseg_prev) ? mseg_next_addr(mseg_prev) : zone->addr;
	a_mseg_new = mseg_new(addr_new, size);
	if (!a_mseg_new)
		return (NULL);
	if (index_of_prev == -1)
		twl_lst_push(zone->msegs, a_mseg_new);
	else
		twl_lst_insert(zone->msegs, index_of_prev + 1, a_mseg_new);
	if (!gmem_get_mseg_by_addr(addr_new))
		return (NULL);
	return (a_mseg_new);
}

void				*zone_malloc(t_zone *zone, size_t size)
{
	t_mseg			*mseg;

	mseg = zone_get_next_suitable_malloc(zone, size);
	if (!mseg)
		return (NULL);
	return (mseg->addr);
}
