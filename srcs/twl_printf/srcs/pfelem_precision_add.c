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

static int	skip(t_pfelem *pfelem)
{
	if ((pfelem->conv_spec == CONV_SPEC_C)
		|| (pfelem->conv_spec == CONV_SPEC_C_UP)
		|| (pfelem->conv_spec == CONV_SPEC_PERCENT))
		return (1);
	return (0);
}

void		pfelem_precision_add(t_pfelem *pfelem)
{
	if (skip(pfelem))
		return ;
	if (pfelem->conv_spec == CONV_SPEC_S || pfelem->conv_spec == CONV_SPEC_S_UP)
		pfelem_precision_handle_strings(pfelem);
	else
		pfelem_precision_handle_digits(pfelem);
}
