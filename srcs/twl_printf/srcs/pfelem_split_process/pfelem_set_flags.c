/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_set_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:04:35 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 18:19:35 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

static void	pfelem_harmonize_flags(t_pfelem *pfelem)
{
	if (pfelem->conv_spec == CONV_SPEC_O
		|| pfelem->conv_spec == CONV_SPEC_O_UP
		|| pfelem->conv_spec == CONV_SPEC_X
		|| pfelem->conv_spec == CONV_SPEC_X_UP
		|| pfelem->conv_spec == CONV_SPEC_P
		|| pfelem->conv_spec == CONV_SPEC_U)
		pfelem->flags &= ~(FLAG_PLUS_MASK | FLAG_SPACE_MASK);
}

void		pfelem_set_flags(t_pfelem *pfelem, char *flags)
{
	if (twl_strchr(flags, FLAG_SHARP))
		pfelem->flags = pfelem->flags | FLAG_SHARP_MASK;
	if (twl_strchr(flags, FLAG_MINUS))
		pfelem->flags = pfelem->flags | FLAG_MINUS_MASK;
	if (twl_strchr(flags, FLAG_ZERO))
		pfelem->flags = pfelem->flags | FLAG_ZERO_MASK;
	if (twl_strchr(flags, FLAG_PLUS))
		pfelem->flags = pfelem->flags | FLAG_PLUS_MASK;
	if (twl_strchr(flags, FLAG_SPACE))
		pfelem->flags = pfelem->flags | FLAG_SPACE_MASK;
	pfelem_harmonize_flags(pfelem);
}
