/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_precision_add.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:23:51 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
