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
}
