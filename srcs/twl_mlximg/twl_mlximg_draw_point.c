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

#include <stddef.h>
#include "twl_mlximg.h"
#include "twl_string.h"

void	mlximg_draw_point(t_mlximg *image, t_twl_point *pt, int color)
{
	char *point_ptr;

	point_ptr = &image->img_data[(pt->x * 4) + (pt->y * image->size_line)];
	twl_memcpy(point_ptr, &(color), (size_t)(sizeof(int)));
}
