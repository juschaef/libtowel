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

#ifndef TWL_MLXIMG_H
# define TWL_MLXIMG_H

# include "twl_point.h"

typedef struct	s_mlximg
{
	void		*mlx;
	void		*img;
	char		*img_data;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlximg;

t_mlximg		*mlximg_new(void *mlx, int width, int height);
void			mlximg_del(t_mlximg *mlximg);

void			mlximg_draw_point(t_mlximg *image, t_twl_point *pt, int color);
void			mlximg_iter(t_mlximg *mlximg, void (*iter_fn)(t_mlximg *mlximg,
								t_twl_point *pt, void *context), void *context);

#endif
