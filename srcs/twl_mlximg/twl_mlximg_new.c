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
#include <mlx.h>
#include "twl_mlximg.h"

t_mlximg	*mlximg_new(void *mlx, int width, int height)
{
	t_mlximg *mlximg;

	mlximg = malloc(sizeof(t_mlximg));
	mlximg->height = height;
	mlximg->width = width;
	mlximg->mlx = mlx;
	mlximg->img = mlx_new_image(mlx, mlximg->width, mlximg->height);
	mlximg->img_data = mlx_get_data_addr(mlximg->img,
		&(mlximg->bits_per_pixel), &(mlximg->size_line), &(mlximg->endian));
	return (mlximg);
}
