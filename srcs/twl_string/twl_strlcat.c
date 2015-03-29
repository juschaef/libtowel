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

#include "twl_string.h"

size_t	twl_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;

	lendst = twl_strlen(dst);
	lensrc = twl_strlen(src);
	if (size <= lendst)
		return (size + lensrc);
	if (lensrc < size - lendst)
	{
		twl_memcpy(dst + lendst, src, lensrc);
		dst += lendst + lensrc;
	}
	else
	{
		twl_memcpy(dst + lendst, src, size - lendst - 1);
		dst += size - 1;
	}
	*dst = '\0';
	return (lensrc + lendst);
}
