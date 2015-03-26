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

#ifndef ZONE_H
# define ZONE_H

# include "twl_lst.h"
# include "twl_xstdio.h"

# include "twl_malloc/mseg.h"

typedef	struct		s_zone
{
	t_lst			*msegs;
	size_t			size;
	void			*addr;
}					t_zone;

t_zone				*zone_new(size_t size);
void				zone_del(t_zone *zone);
void				zone_del_void(void *zone);
void				*zone_malloc(t_zone *zone, size_t size);
void				zone_print(t_zone *zone);

typedef struct		s_is_suitable_size_fn_context
{
	size_t			size;
	t_mseg			*mseg_prev;
}					t_is_suitable_size_fn_context;

#endif
