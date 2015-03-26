/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_mlximg_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 11:49:03 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include <mlx.h>
#include "twl_mlximg.h"

t_mlximg	*mlximg_new(void *mlx, int width, int height)
{
	t_mlximg *mlximg;

	mlximg = twl_malloc(sizeof(t_mlximg));
	mlximg->height = height;
	mlximg->width = width;
	mlximg->mlx = mlx;
	mlximg->img = mlx_new_image(mlx, mlximg->width, mlximg->height);
	mlximg->img_data = mlx_get_data_addr(mlximg->img,
		&(mlximg->bits_per_pixel), &(mlximg->size_line), &(mlximg->endian));
	return (mlximg);
}
