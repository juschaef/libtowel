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

static void		pfelem_add_flags_sharp(t_pfelem *pfelem)
{
	char prefix[3];

	*prefix = 0;
	if (twl_strequ(pfelem->str, "0"))
		return ;
	if (pfelem->conv_spec == CONV_SPEC_X)
		twl_strcpy(prefix, "0x");
	else if (pfelem->conv_spec == CONV_SPEC_X_UP)
		twl_strcpy(prefix, "0X");
	if (*prefix)
		pfelem->prefix = twl_strjoinfree(pfelem->prefix, prefix, 'l');
	if ((pfelem->conv_spec == CONV_SPEC_O)
									|| (pfelem->conv_spec == CONV_SPEC_O_UP))
		pfelem->str = twl_strjoinfree("0", pfelem->str, 'r');
}

static void		pfelem_add_flags_prefix(t_pfelem *pfelem, char *prefix)
{
	if (*pfelem->str != '-')
		pfelem->prefix = twl_strjoinfree(pfelem->prefix, prefix, 'l');
}

static int		skip_cases(t_pfelem *pfelem)
{
	int is_char;
	int is_string;
	int is_percent;

	is_char = (pfelem->conv_spec == CONV_SPEC_C
									|| pfelem->conv_spec == CONV_SPEC_C_UP);
	is_string = (pfelem->conv_spec == CONV_SPEC_S
									|| pfelem->conv_spec == CONV_SPEC_S_UP);
	is_percent = (pfelem->conv_spec == CONV_SPEC_PERCENT);
	if (is_char || is_string || is_percent)
		return (1);
	return (0);
}

void			pfelem_flag_add(t_pfelem *pfelem)
{
	if (skip_cases(pfelem))
		return ;
	if (pfelem->flags & FLAG_SHARP_MASK)
		pfelem_add_flags_sharp(pfelem);
	if (pfelem->flags & FLAG_PLUS_MASK)
		pfelem_add_flags_prefix(pfelem, "+");
	else if ((pfelem->flags & FLAG_SPACE_MASK))
		pfelem_add_flags_prefix(pfelem, " ");
}
