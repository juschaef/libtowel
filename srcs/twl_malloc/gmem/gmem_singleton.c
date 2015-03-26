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

#include "twl_malloc.h"
#include "twl_malloc/gmem.h"
#include "twl_malloc/smem.h"

t_gmem				*gmem_singleton(void)
{
	static t_gmem	gmem;
	static bool		initialized = false;

	if (initialized)
		return (&gmem);
	initialized = true;
	gmem.zone_mgr_tiny = zone_mgr_new(ZONE_NAME_TINY);
	gmem.zone_mgr_small = zone_mgr_new(ZONE_NAME_SMALL);
	gmem.zone_mgr_large = zone_mgr_new(ZONE_NAME_LARGE);
	if (!gmem.zone_mgr_tiny || !gmem.zone_mgr_small || !gmem.zone_mgr_large)
		return (NULL);
	return (&gmem);
}
