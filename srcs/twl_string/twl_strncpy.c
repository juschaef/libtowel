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

char			*twl_strncpy(char *dst, const char *src, size_t limit)
{
	size_t		index;

	index = 0;
	while (src[index] != '\0' && index < limit)
	{
		dst[index] = src[index];
		index += 1;
	}
	while (index < limit)
	{
		dst[index] = '\0';
		index += 1;
	}
	return (dst);
}
