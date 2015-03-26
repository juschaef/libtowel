/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_mlximg_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 11:48:51 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include <mlx.h>
#include "twl_mlximg.h"

void mlximg_del(t_mlximg *mlximg)
{
	mlx_destroy_image(mlximg->mlx, mlximg->img);
	twl_free(mlximg);
}
