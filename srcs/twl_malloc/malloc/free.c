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

#include "twl_malloc.h"
#include "twl_malloc/mseg_mgr.h"
#include "twl_malloc/zone_mgr.h"

void				twl_free(void *addr)
{
	static pthread_mutex_t		free_mutex;

	if (addr == NULL)
		return ;
	pthread_mutex_lock(&free_mutex);
	zone_mgr_del_by_addr(gmem_singleton()->zone_mgr_tiny, addr);
	zone_mgr_del_by_addr(gmem_singleton()->zone_mgr_small, addr);
	zone_mgr_del_by_addr(gmem_singleton()->zone_mgr_large, addr);
	pthread_mutex_unlock(&free_mutex);
}
