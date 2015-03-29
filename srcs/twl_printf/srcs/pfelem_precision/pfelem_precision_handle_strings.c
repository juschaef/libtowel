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

static void		pfelem_truncate_widestring(t_pfelem *pfelem)
{
	char	*str;
	int		len;
	int		is_end_of_char;

	str = pfelem->str;
	len = (int)twl_strlen(str);
	is_end_of_char = 0;
	while (len > 0)
	{
		is_end_of_char = (((str[len] & 192) == 192)
											|| !((str[len] & 128) == 128));
		if ((len <= pfelem->precision) && is_end_of_char)
			break ;
		len--;
	}
	str[len] = 0;
}

static void		pfelem_truncate_string(t_pfelem *pfelem)
{
	size_t		len;

	if (pfelem->precision < 0)
		return ;
	len = twl_strlen(pfelem->str);
	if (pfelem->precision < (int)len)
	{
		if (pfelem->conv_spec == CONV_SPEC_S_UP)
			pfelem_truncate_widestring(pfelem);
		else
			pfelem->str[pfelem->precision] = '\0';
	}
}

void			pfelem_precision_handle_strings(t_pfelem *pfelem)
{
	if (pfelem->precision == PRECISION_WILDCARD_VAL)
		pfelem_precision_set_wildcard(pfelem);
	pfelem_truncate_string(pfelem);
}
