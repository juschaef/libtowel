/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg_draw_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/01/15 14:52:21 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlximg.h>
#include <stddef.h>
#include <libft.h>
#include <mlx.h>

void	mlximg_draw_point(t_mlximg *image, t_twl_point *pt, int color)
{
	char *point_ptr;

	point_ptr = &image->img_data[(pt->x * 4) + (pt->y * image->size_line)];
	twl_memcpy(point_ptr, &(color), (size_t)(sizeof(int)));
}
