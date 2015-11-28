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

#ifndef TWL_MLX_IMG_H
# define TWL_MLX_IMG_H

# include <stddef.h>

# include "mlx.h"
# include "twl_string.h"

typedef struct		s_twl_mlx_img
{
	void			*img_ptr;
	char			*img_data;
	int				img_size_line;
	int				img_bits_per_pixel;
	int				img_endian;
	int				height;
	int				width;
}					t_twl_mlx_img;

t_twl_mlx_img		*twl_mlx_img_new(void *mlx, int width, int height);
void				twl_mlx_img_del(t_twl_mlx_img *this);

void				twl_mlx_img_draw_point(t_twl_mlx_img *this,
													int x, int y, int value);

#endif
