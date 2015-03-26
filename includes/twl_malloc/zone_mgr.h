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

#ifndef ZONE_MGR_H
# define ZONE_MGR_H

# include "twl_malloc/zone.h"
# include "twl_malloc/mseg.h"

typedef	struct		s_zone_mgr
{
	char			*name;
	t_lst			*zones;
	size_t			size;
}					t_zone_mgr;

t_zone_mgr			*zone_mgr_new(char *name);
void				zone_mgr_del(t_zone_mgr *zone_mgr);
void				*zone_mgr_malloc(t_zone_mgr *zone_mgr, size_t size);
t_zone				*zone_get_zone(t_zone_mgr *zone_mgr, size_t size);
size_t				mseg_mgr_get_total_size(t_lst *msegs);
void				zone_mgr_del_by_addr(t_zone_mgr *zone_mgr, void *addr);
void				zone_mgr_del_empty_zones(t_zone_mgr *zone_mgr);
t_mseg				*zone_mgr_get_mseg_by_addr(t_zone_mgr *zone_mgr,
																	void *addr);

#endif
