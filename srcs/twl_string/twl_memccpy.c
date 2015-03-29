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
