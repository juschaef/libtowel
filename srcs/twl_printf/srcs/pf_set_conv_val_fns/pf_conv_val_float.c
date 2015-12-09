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

#include "twl_printf.h"

void	*pf_conv_val_float(t_pf *pf)
{
	double	*lptr;
	int		sign;

	lptr = malloc(sizeof(double));
	*lptr = va_arg(pf->arglist, double);
	sign = (*lptr >= 0) ? 1 : -1;
	*lptr += 0.0000001 * (double)sign;
	return (lptr);
}
