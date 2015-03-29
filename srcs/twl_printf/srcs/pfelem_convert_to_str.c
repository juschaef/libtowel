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
#include "twl_arr.h"

static void		pfelem_process_raw_string(t_pfelem *pfelem)
{
	char *tmp;

	if (twl_strequ(pfelem->raw, "%%"))
		tmp = "%";
	else
		tmp = pfelem->raw;
	free(pfelem->str);
	pfelem->str = twl_strdup(tmp);
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
		str = twl_strnew(1);
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
		if (twl_strchr(CONV_SPEC_ALL, pfelem->conv_spec))
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
