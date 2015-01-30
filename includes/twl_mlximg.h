/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_mlximg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:56:14 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/30 15:14:13 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_MLXIMG_H
# define TWL_MLXIMG_H

# include <twl_point.h>

typedef struct	s_mlximg
{
	void		*img;
	char		*img_data;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlximg;

void			mlximg_draw_point(t_mlximg *image, t_twl_point *pt, int color);
t_mlximg		*mlximg_init(void *mlx, int width, int height);
void			mlximg_iter(t_mlximg *mlximg, void (*iter_fn)(t_mlximg *mlximg,
								t_twl_point *pt, void *context), void *context);

#endif
