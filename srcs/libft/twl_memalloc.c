/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/13 11:17:09 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static void		twl_bzero(void *s, size_t n)
{
	size_t	index;
	char	*temp;

	temp = s;
	index = 0;
	while (index < n)
	{
		temp[index] = 0;
		index++;
	}
}

void			*twl_memalloc(size_t size)
{
	void *mem;

	if (!(mem = (void *)malloc(size)))
		return (NULL);
	twl_bzero(mem, size);
	return (mem);
}
