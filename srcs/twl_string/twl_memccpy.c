/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:11:11 by juschaef         ###   ########.fr       */
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
