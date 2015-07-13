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

#ifndef TWL_VECTOR2_H
# define TWL_VECTOR2_H

# include <stdbool.h>

typedef struct		s_vector2
{
	int				x;
	int				y;
}					t_vector2;

typedef struct		s_delta
{
	int				delta_x;
	int				sign_x;
	int				delta_y;
	int				sign_y;
	int				error;
}					t_delta;

t_vector2			*twl_vector2_new(int x, int y);
void				twl_vector2_del(t_vector2 *this);

bool				twl_vector2_is_equal(t_vector2 *this, t_vector2 *other);

void				twl_vector2_bresenham(t_vector2 *this, t_vector2 *dst,
					void (*fn)(int x, int y, void *), void *ctx);

#endif
