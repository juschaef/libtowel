/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:06:27 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:23:37 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <stdlib.h>

void	*twl_memdup(const void *s, size_t n)
{
	void	*dup;

	if (!s)
		return (NULL);
	dup = malloc(n);
	if (!dup)
		return (NULL);
	twl_memcpy(dup, s, n);
	return (dup);
}
