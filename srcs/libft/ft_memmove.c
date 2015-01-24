/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/23 09:46:47 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*twl_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	str = (unsigned char*)malloc(sizeof(*str) * len);
	twl_memcpy(str, src, len);
	twl_memcpy(dst, str, len);
	free(str);
	return (dst);
}
