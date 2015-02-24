/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_mlximg_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/02/24 11:32:24 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_mlximg.h>
#include <stdlib.h>
#include <mlx.h>

void mlximg_del(t_mlximg *mlximg)
{
	mlx_destroy_image(mlximg->mlx, mlximg->img);
	free(mlximg);
}
