/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_precision_handle_digits.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:20:54 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:28:30 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

static int		pfelem_is_not_octal_sharp_zero(t_pfelem *pfelem)
{
	int		is_octal_conv;
	int		is_sharp_active;

	is_octal_conv = (pfelem->conv_spec == CONV_SPEC_O
									|| pfelem->conv_spec == CONV_SPEC_O_UP);
	is_sharp_active = (pfelem->flags & FLAG_SHARP_MASK);
	return (!(is_octal_conv && is_sharp_active));
}

static int		pfelem_not_print_zero(t_pfelem *pfelem)
{
	return (pfelem_is_not_octal_sharp_zero(pfelem));
}

static int		pfelem_is_zero_value(t_pfelem *pfelem)
{
	return (twl_strequ(pfelem->str, "0") || twl_strequ(pfelem->str, "0x0"));
}

static void		pfelem_precision_pad_handle_neg(t_pfelem *pfelem)
{
	char	*tmp;
	int		is_neg;

	tmp = pfelem->str;
	is_neg = 0;
	if (*(pfelem->str) == '-')
	{
		is_neg = 1;
		pfelem->str++;
	}
	pfelem->str = twl_strpad(pfelem->str, pfelem->precision,
														FT_STRPAD_LEFT, '0');
	twl_free(tmp);
	tmp = pfelem->str;
	if (is_neg)
	{
		pfelem->str = twl_strjoin("-", pfelem->str);
		twl_free(tmp);
	}
}

void			pfelem_precision_handle_digits(t_pfelem *pfelem)
{
	if (pfelem->precision == PRECISION_WILDCARD_VAL)
		pfelem_precision_set_wildcard(pfelem);
	if (pfelem->precision > 0)
	{
		pfelem_precision_pad_handle_neg(pfelem);
	}
	else if (pfelem->precision == 0)
	{
		if (pfelem_is_zero_value(pfelem))
		{
			if (pfelem_not_print_zero(pfelem))
			{
				pfelem->str[twl_strlen(pfelem->str) - 1] = '\0';
			}
		}
	}
}
