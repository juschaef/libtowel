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

#include "twl_mlx_img.h"

void				twl_mlx_img_draw_point(t_twl_mlx_img *this,
												int x, int y, int value)
{
	int				index;
	char			*point_addr;

	index = (x * 4) + (y * this->img_size_line);
	point_addr = &(this->img_data[index]);
	twl_memcpy(point_addr, &value, (size_t)(sizeof(int)));
}
