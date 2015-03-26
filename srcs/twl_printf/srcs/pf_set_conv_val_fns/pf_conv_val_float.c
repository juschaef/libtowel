/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_val_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:44:43 by yyang             #+#    #+#             */
/*   Updated: 2015/01/12 16:50:30 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

void *pf_conv_val_float(t_pf *pf)
{
	double	*lptr;
	int		sign;

	lptr = twl_malloc(sizeof(double));
	*lptr = va_arg(pf->arglist, double);
	sign = (*lptr >= 0) ? 1 : -1;
	*lptr += 0.0000001 * (double)sign;
	return (lptr);
}
