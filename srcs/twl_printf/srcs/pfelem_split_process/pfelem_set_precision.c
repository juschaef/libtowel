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
