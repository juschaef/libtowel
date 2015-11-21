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

#ifndef TWL_POINT_H
# define TWL_POINT_H

# define T_TWL_POINT(x, y)	((t_twl_point){(x), (y)})

typedef struct		s_twl_point
{
	int x;
	int y;
}					t_twl_point;

typedef struct		s_twl_dpoint
{
	double x;
	double y;
}					t_twl_dpoint;

typedef struct		s_twl_dcomplex
{
	double	r;
	double	i;
}					t_twl_dcomplex;

t_twl_point			*twl_point_init(int x, int y);
void				twl_point_del(t_twl_point *point);
t_twl_dpoint		*twl_dpoint_init(double x, double y);
t_twl_dcomplex		twl_dcomplex_new(double r, double i);

#endif
