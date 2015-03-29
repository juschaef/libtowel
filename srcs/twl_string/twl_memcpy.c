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

void	*twl_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*chardst;
	unsigned char	*charsrc;
	size_t			index;

	chardst = (unsigned char *)dst;
	charsrc = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		chardst[index] = charsrc[index];
		index++;
	}
	return (dst);
}
