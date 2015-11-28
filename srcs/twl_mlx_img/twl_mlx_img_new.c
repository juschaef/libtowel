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

#include "twl_xstdlib.h"

#include "twl_mlx_img.h"

t_twl_mlx_img		*twl_mlx_img_new(void *mlx, int width, int height)
{
	t_twl_mlx_img	*this;

	this = twl_malloc_x0(sizeof(t_twl_mlx_img));
	this->img_ptr = mlx_new_image(mlx, width, height);
	this->img_data = mlx_get_data_addr(this->img_ptr,
												&(this->img_bits_per_pixel),
												&(this->img_size_line),
												&(this->img_endian));
	this->height = height;
	this->width = width;
	return (this);
}
