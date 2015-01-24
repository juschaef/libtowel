/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_pre_str_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:29:08 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		pfelem_add_pointer_prefix(t_pfelem *pfelem)
{
	if ((pfelem->conv_spec == CONV_SPEC_P)
		&& !(pfelem->flags & FLAG_ZERO_MASK))
		pfelem->str = ft_strjoinfree(PREFIX_FOR_POINTER, pfelem->str, 'r');
}

static void		pfelem_add_prefix(t_pfelem *pfelem)
{
	if (!pfelem_fill_before_padding(pfelem))
		pfelem->str = ft_strjoinfree(pfelem->prefix, pfelem->str, 'r');
}

static void		pfelem_harmonize(t_pfelem *pfelem)
{
	if ((pfelem->conv_spec == CONV_SPEC_C)
		|| (pfelem->conv_spec == CONV_SPEC_C_UP)
		|| (pfelem->conv_spec == CONV_SPEC_S)
		|| (pfelem->conv_spec == CONV_SPEC_S_UP)
		|| !(ft_strchr(CONV_SPEC_ALL, pfelem->conv_spec)))
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
