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

static void		pfelem_add_pointer_prefix(t_pfelem *pfelem)
{
	if ((pfelem->conv_spec == CONV_SPEC_P)
		&& !(pfelem->flags & FLAG_ZERO_MASK))
		pfelem->str = twl_strjoinfree(PREFIX_FOR_POINTER, pfelem->str, 'r');
}

static void		pfelem_add_prefix(t_pfelem *pfelem)
{
	if (!pfelem_fill_before_padding(pfelem))
		pfelem->str = twl_strjoinfree(pfelem->prefix, pfelem->str, 'r');
}

static void		pfelem_harmonize(t_pfelem *pfelem)
{
	if ((pfelem->conv_spec == CONV_SPEC_C)
		|| (pfelem->conv_spec == CONV_SPEC_C_UP)
		|| (pfelem->conv_spec == CONV_SPEC_S)
		|| (pfelem->conv_spec == CONV_SPEC_S_UP)
		|| !(twl_strchr(CONV_SPEC_ALL, pfelem->conv_spec)))
		pfelem->precision = PRECISION_NOT_SET;
	if (pfelem->precision != PRECISION_NOT_SET)
		pfelem->flags = pfelem->flags & ~FLAG_ZERO_MASK;
}

void			pfelem_pre_str_conv(t_pfelem *pfelem)
{
	pfelem_harmonize(pfelem);
	pfelem_add_prefix(pfelem);
	pfelem_add_pointer_prefix(pfelem);
}
