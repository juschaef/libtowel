/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:55:14 by yyang             #+#    #+#             */
/*   Updated: 2015/03/27 16:49:21 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_MATH_H
# define TWL_MATH_H

# define T_FT_COMPLEX(r, i)	((t_twl_complex){(r), (i)})

typedef struct		s_twl_complex
{
	long double		r;
	long double		i;
}					t_twl_complex;

int					twl_abs(int n);
double				twl_sqrt(const double m);

#endif
