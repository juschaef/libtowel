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
#include "twl_malloc/mseg.h"

void				*twl_realloc(void *old_malloc_addr, size_t size)
{
	void						*new_malloc_addr;
	t_mseg						*mseg;
	static pthread_mutex_t		realloc_mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&realloc_mutex);
	mseg = gmem_get_mseg_by_addr(old_malloc_addr);
	if (!mseg)
		return (NULL);
	new_malloc_addr = twl_malloc(size);
	if (!new_malloc_addr)
		return (NULL);
	twl_memcpy(new_malloc_addr, old_malloc_addr, mseg->size);
	twl_free(old_malloc_addr);
	pthread_mutex_unlock(&realloc_mutex);
	return (new_malloc_addr);
}
