/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_malloc_x0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 18:55:21 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/15 12:17:51 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_xstdlib.h>
#include <twl_string.h>

void	*twl_malloc_x0(int size)
{
	void *new;
	new = twl_xmalloc(size);
	twl_bzero(new, size);
	return (new);
}
