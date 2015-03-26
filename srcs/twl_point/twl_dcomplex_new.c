/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dcomplex_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/02/04 17:31:37 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_point.h"

t_twl_dcomplex	twl_dcomplex_new(double r, double i)
{
	t_twl_dcomplex cpx;

	cpx.r = r;
	cpx.i = i;
	return (cpx);
}
