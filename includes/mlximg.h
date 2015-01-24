/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlximg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:56:14 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/17 14:48:48 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXIMG_H
# define MLXIMG_H

# include <ft_point.h>

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

t_mlximg		*mlximg_init(void *mlx, int width, int height);
void			mlximg_draw_point(t_mlximg *image, t_ft_point *pt, int color);
void			mlximg_iter(t_mlximg *mlximg, void (*iter_fn)(t_mlximg *mlximg,
								t_ft_point *pt, void *context), void *context);

#endif
