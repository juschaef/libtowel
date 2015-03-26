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
#include "twl_xstdio.h"
#include "limits.h"

void				*twl_malloc(size_t size)
{
	void						*new_malloc;
	static pthread_mutex_t		malloc_mutex = PTHREAD_MUTEX_INITIALIZER;
	t_gmem						*gmem;

	gmem = gmem_singleton();
	if (!gmem || size < 1 || size > LONG_MAX)
		return (NULL);
	pthread_mutex_lock(&malloc_mutex);
	if (size <= CONST_N)
	{
		new_malloc = zone_mgr_malloc(gmem->zone_mgr_tiny, size);
	}
	else if (size <= CONST_M)
	{
		new_malloc = zone_mgr_malloc(gmem->zone_mgr_small, size);
	}
	else
	{
		new_malloc = zone_mgr_malloc(gmem->zone_mgr_large, size);
	}
	pthread_mutex_unlock(&malloc_mutex);
	return (new_malloc);
}
