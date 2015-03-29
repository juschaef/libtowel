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

static int		pfelem_get_pad_dir(t_pfelem *pfelem)
{
	if (pfelem->flags & FLAG_MINUS_MASK)
		return (FT_STRPAD_RIGHT);
	else
		return (FT_STRPAD_LEFT);
}

static char		pfelem_get_fill_char(t_pfelem *pfelem)
{
	if ((pfelem->flags & FLAG_ZERO_MASK)
		&& !(pfelem->flags & FLAG_MINUS_MASK)
		&& (pfelem->precision == PRECISION_NOT_SET))
		return ('0');
	return (' ');
}

static void		pfelem_min_width_set_wildcard(t_pfelem *pfelem)
{
	pfelem->min_width = *((int *)(pfelem->values[0]));
	if (pfelem->min_width < 0)
	{
		pfelem->min_width *= -1;
		pfelem->flags = pfelem->flags | FLAG_MINUS_MASK;
	}
}

static void		pfelem_ajust_min_width_if_prefix(t_pfelem *pfelem)
{
	if (pfelem->conv_spec == CONV_SPEC_P
		&& (pfelem->flags & FLAG_ZERO_MASK))
		pfelem->min_width -= twl_strlen(PREFIX_FOR_POINTER);
	if (pfelem_fill_before_padding(pfelem))
		pfelem->min_width -= twl_strlen(pfelem->prefix);
}

void			pfelem_min_width_add(t_pfelem *pfelem)
{
	char	fill_char;
	int		pad_dir;

	if (pfelem->min_width == MIN_WIDTH_WILDCARD_VAL)
		pfelem_min_width_set_wildcard(pfelem);
	pfelem_ajust_min_width_if_prefix(pfelem);
	if (pfelem->min_width > 0)
	{
		fill_char = pfelem_get_fill_char(pfelem);
		pad_dir = pfelem_get_pad_dir(pfelem);
		pfelem_min_width_pad(pfelem, pad_dir, fill_char);
	}
}
