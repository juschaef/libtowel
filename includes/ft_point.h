/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:35:02 by yyang             #+#    #+#             */
/*   Updated: 2015/01/17 14:49:02 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

# define T_FT_POINT(x, y)	((t_ft_point){(x), (y)})

typedef struct	s_ft_point
{
	int x;
	int y;
}				t_ft_point;

t_ft_point		*ft_point_init(int x, int y);

#endif
