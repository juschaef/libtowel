/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 12:17:36 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:13:01 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_string.h"

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
