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

#ifndef GMEM_H
# define GMEM_H

# include "twl_malloc/zone.h"
# include "twl_malloc/zone_mgr.h"

typedef struct		s_gmem
{
	t_zone_mgr		*zone_mgr_tiny;
	t_zone_mgr		*zone_mgr_small;
	t_zone_mgr		*zone_mgr_large;
}					t_gmem;

t_gmem				*gmem_singleton(void);
t_mseg				*gmem_get_mseg_by_addr(void *addr);

#endif
