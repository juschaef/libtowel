/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_convert_to_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/14 13:51:17 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <arr.h>

static void		pfelem_process_raw_string(t_pfelem *pfelem)
{
	char *tmp;

	if (ft_strequ(pfelem->raw, "%%"))
		tmp = "%";
	else
		tmp = pfelem->raw;
	free(pfelem->str);
	pfelem->str = ft_strdup(tmp);
}

static char		*pfelem_get_str(t_pfelem *pfelem)
{
	char *str;

	if (pfelem_has_valid_conv_spec(pfelem))
	{
		str = pfelem->conv_to_str(pfelem->values[pfelem->values_count - 1]);
	}
	else
	{
		str = ft_strnew(1);
		*str = pfelem->conv_spec;
	}
	return (str);
}

static void		pfelem_process_conversion(t_pfelem *pfelem)
{
	char *tmp;

	if (!pfelem_is_raw_string(pfelem))
	{
		tmp = pfelem->str;
		pfelem->str = pfelem_get_str(pfelem);
		free(tmp);
		if (ft_strchr(CONV_SPEC_ALL, pfelem->conv_spec))
		{
			pfelem_flag_add(pfelem);
			pfelem_precision_add(pfelem);
		}
		pfelem_pre_str_conv(pfelem);
		pfelem_min_width_add(pfelem);
		pfelem_post_str_conv(pfelem);
	}
}

void			pfelem_convert_to_str(t_pfelem *pfelem)
{
	if (pfelem_is_raw_string(pfelem))
		pfelem_process_raw_string(pfelem);
	else
		pfelem_process_conversion(pfelem);
}
