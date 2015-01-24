/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/13 11:17:45 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void		ft_bzero(void *s, size_t n)
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

char			*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	if (!dst || !src)
		return (void *)0;
	if (n <= 0)
		return (dst);
	ft_bzero(dst, n);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
