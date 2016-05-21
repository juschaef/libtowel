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

static inline void	loop_forward_fn(void *dst, const void *src, size_t n)
{
	src += n;
	dst += n;
	while (n > sizeof(long))
	{
		dst -= sizeof(long);
		src -= sizeof(long);
		*(long *)dst = *(long *)src;
		n -= sizeof(long);
	}
	while (n)
	{
		dst -= sizeof(char);
		src -= sizeof(char);
		*(char *)dst = *(char *)src;
		n -= sizeof(char);
	}
}

static inline void	loop_backward_fn(void *dst, const void *src, size_t n)
{
	while (n > sizeof(long))
	{
		*(long *)dst = *(long *)src;
		dst += sizeof(long);
		src += sizeof(long);
		n -= sizeof(long);
	}
	while (n)
	{
		*(char *)dst = *(char *)src;
		dst += sizeof(char);
		src += sizeof(char);
		n -= sizeof(char);
	}
}

void				*twl_memmove(void *dst, const void *src, size_t n)
{
	if (n == 0 || dst == src)
		return (dst);
	if (src > dst)
		loop_backward_fn(dst, src, n);
	else
		loop_forward_fn(dst, src, n);
	return (dst);
}
