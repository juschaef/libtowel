/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_set_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:04:46 by yyang             #+#    #+#             */
/*   Updated: 2015/01/18 11:59:11 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

void		pfelem_set_precision(t_pfelem *pfelem, char *raw)
{
	if (*raw == '.')
	{
		pfelem->precision = 0;
		raw++;
		pfelem->precision = pfelem_get_value_or_wildcard(raw,
			PRECISION_WILDCARD_VAL,
			pfelem->precision);
	}
}
