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

#include "twl_mlximg.h"

#define DEFAULT_COLOR 0x000000

void mlximg_iter(t_mlximg *mlximg,
	void (*iter_fn)(t_mlximg *mlximg, t_twl_point *pt, void *context),
	void *context)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlximg->height)
	{
		x = 0;
		while (x < mlximg->width)
		{
			iter_fn(mlximg, &(t_twl_point){x, y}, context);
			x++;
		}
		y++;
	}
}
