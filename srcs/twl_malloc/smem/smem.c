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

#include "twl_malloc/gmem.h"
#include "twl_malloc/smem.h"

void				*smem_get(t_smem type)
{
	if (type == STATIC_MEM_ZONE_MGR)
		return (static_mem_zone_mgr());
	else if (type == STATIC_MEM_ZONE)
		return (static_mem_zone());
	else if (type == STATIC_MEM_MSEG)
		return (static_mem_mseg());
	return (NULL);
}
