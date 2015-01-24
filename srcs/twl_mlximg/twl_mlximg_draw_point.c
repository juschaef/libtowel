/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_mlximg_draw_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:05:50 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_mlximg.h>
#include <stddef.h>
#include <libft.h>
#include <mlx.h>

void	mlximg_draw_point(t_mlximg *image, t_twl_point *pt, int color)
{
	char *point_ptr;

	point_ptr = &image->img_data[(pt->x * 4) + (pt->y * image->size_line)];
	twl_memcpy(point_ptr, &(color), (size_t)(sizeof(int)));
}
