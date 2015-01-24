/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 12:17:36 by yyang             #+#    #+#             */
/*   Updated: 2014/11/21 12:20:09 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*twl_realloc(void *ptr, size_t size)
{
	void	*dup;

	dup = twl_memalloc(size);
	if (!dup)
		return (NULL);
	if (ptr)
	{
		if (dup)
			twl_memcpy(dup, ptr, size);
		twl_memdel(&ptr);
	}
	return (dup);
}
