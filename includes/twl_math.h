/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:55:14 by yyang             #+#    #+#             */
/*   Updated: 2015/01/15 14:58:40 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# define T_FT_COMPLEX(r, i)	((t_twl_complex){(r), (i)})

typedef struct	s_twl_complex
{
	long double		r;
	long double		i;
}				t_twl_complex;

#endif
