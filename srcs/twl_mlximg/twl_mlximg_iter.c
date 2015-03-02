/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_mlximg_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:02:57 by juschaef         ###   ########.fr       */
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
