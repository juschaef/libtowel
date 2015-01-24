/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 12:17:36 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:35:58 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <stdlib.h>

void		*twl_realloc(void *ptr, size_t size)
{
	void	*dup;

	dup = malloc(size);
	if (!dup)
		return (NULL);
	if (ptr)
	{
		if (dup)
			twl_memcpy(dup, ptr, size);
		free(ptr);
	}
	return (dup);
}
