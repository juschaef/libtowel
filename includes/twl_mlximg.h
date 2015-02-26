/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_mlximg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:56:14 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/25 22:54:05 by gbarraul         ###   ########.fr       */
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
