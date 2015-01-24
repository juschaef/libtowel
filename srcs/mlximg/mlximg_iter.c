/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/01/17 14:49:40 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlximg.h>

#define DEFAULT_COLOR 0x000000

void mlximg_iter(t_mlximg *mlximg,
	void (*iter_fn)(t_mlximg *mlximg, t_ft_point *pt, void *context),
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
			iter_fn(mlximg, &(t_ft_point){x, y}, context);
			x++;
		}
		y++;
	}
}
