/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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

char			*twl_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	if (!dst || !src)
		return (void *)0;
	if (n <= 0)
		return (dst);
	twl_bzero(dst, n);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
