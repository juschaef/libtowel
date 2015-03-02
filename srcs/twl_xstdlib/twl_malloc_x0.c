/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_malloc_x0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 18:55:21 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/17 18:02:03 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_xstdlib.h"
#include "twl_string.h"

void	*twl_malloc_x0(int size)
{
	void *new_malloc;

	new_malloc = twl_xmalloc(size);
	twl_bzero(new_malloc, size);
	return (new_malloc);
}
