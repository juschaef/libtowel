/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:11:13 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*twl_memchr(const void *s, int c, size_t n)
{
	unsigned char *ucs;

	if (!s || n == 0)
		return (NULL);
	ucs = (unsigned char *)s;
	while (n--)
	{
		if (*ucs == (unsigned char)c)
			return (ucs);
		ucs++;
	}
	return (NULL);
}
