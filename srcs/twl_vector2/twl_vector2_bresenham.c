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

#include <stdlib.h>
#include <stdio.h>

#include "twl_math.h"
#include "twl_vector2.h"

static t_delta		init_delta(t_vector2 *src, t_vector2 *dst)
{
	t_delta			delta;

	delta.delta_x = twl_abs(dst->x - src->x);
	delta.sign_x = src->x < dst->x ? 1 : -1;
	delta.delta_y = twl_abs(dst->y - src->y);
	delta.sign_y = src->y < dst->y ? 1 : -1;
	delta.error = (delta.delta_x > delta.delta_y ? delta.delta_x :
														-(delta.delta_y)) / 2;
	return (delta);
}

void				twl_vector2_bresenham(t_vector2 *this, t_vector2 *dst,
					void (*fn)(int x, int y, void *), void *ctx)
{
	t_delta			delta;
	int				x;
	int				y;
	int				e2;

	delta = init_delta(this, dst);
	x = this->x;
	y = this->y;
	while (1)
	{
		fn(x, y, ctx);
		if (x == dst->x && y == dst->y)
			break ;
		e2 = delta.error;
		if (e2 > -(delta.delta_x))
		{
			delta.error -= delta.delta_y;
			x += delta.sign_x;
		}
		if (e2 < delta.delta_y)
		{
			delta.error += delta.delta_x;
			y += delta.sign_y;
		}
	}
}
