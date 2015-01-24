/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:06:27 by yyang             #+#    #+#             */
/*   Updated: 2014/12/19 11:59:15 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*twl_memdup(const void *s, size_t n)
{
	void	*dup;

	if (!s)
		return (NULL);
	dup = twl_memalloc(n);
	if (!dup)
		return (NULL);
	twl_memcpy(dup, s, n);
	return (dup);
}
