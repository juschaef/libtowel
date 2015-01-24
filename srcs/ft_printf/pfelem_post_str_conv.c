/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_post_str_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:31:17 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		pfelem_add_pointer_prefix(t_pfelem *pfelem)
{
	if ((pfelem->conv_spec == CONV_SPEC_P)
		&& (pfelem->flags & FLAG_ZERO_MASK))
		pfelem->str = ft_strjoinfree(PREFIX_FOR_POINTER, pfelem->str, 'r');
}

static void		pfelem_add_prefix(t_pfelem *pfelem)
{
	if (pfelem_fill_before_padding(pfelem))
		pfelem->str = ft_strjoinfree(pfelem->prefix, pfelem->str, 'r');
}

void			pfelem_post_str_conv(t_pfelem *pfelem)
{
	pfelem_add_prefix(pfelem);
	pfelem_add_pointer_prefix(pfelem);
}
