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
		&& (pfelem->flags & FLAG_ZERO_MASK))
		pfelem->str = twl_strjoinfree(PREFIX_FOR_POINTER, pfelem->str, 'r');
}

static void		pfelem_add_prefix(t_pfelem *pfelem)
{
	if (pfelem_fill_before_padding(pfelem))
		pfelem->str = twl_strjoinfree(pfelem->prefix, pfelem->str, 'r');
}

void			pfelem_post_str_conv(t_pfelem *pfelem)
{
	pfelem_add_prefix(pfelem);
	pfelem_add_pointer_prefix(pfelem);
}
