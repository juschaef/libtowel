/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/18 14:41:24 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*twl_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *chardst;
	unsigned char *charsrc;

	chardst = (unsigned char *)dst;
	charsrc = (unsigned char *)src;
	while (n--)
	{
		if ((unsigned char)*charsrc == (unsigned char)c)
		{
			*chardst++ = *charsrc++;
			return (chardst);
		}
		*chardst++ = *charsrc++;
	}
	return (NULL);
}
