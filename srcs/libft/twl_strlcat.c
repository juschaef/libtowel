/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/09 18:53:20 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
