/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_precision_set_wildcard.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:17:38 by yyang             #+#    #+#             */
/*   Updated: 2015/01/14 14:48:42 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

void	pfelem_precision_set_wildcard(t_pfelem *pfelem)
{
	size_t	wildcard_count;
	size_t	index;
	int		precision;

	wildcard_count = twl_strcountchar(pfelem->raw, '*');
	index = 0;
	if (wildcard_count == 1)
		index = 0;
	else if (wildcard_count == 2)
		index = 1;
	precision = *((int *)(pfelem->values[index]));
	if (precision < 0)
		pfelem->precision = PRECISION_NOT_SET;
	else
		pfelem->precision = precision;
	free(pfelem->values[index]);
}
