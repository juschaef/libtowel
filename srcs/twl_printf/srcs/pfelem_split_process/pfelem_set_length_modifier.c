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

static char		*pfelem_get_harmonized_length_modifier(t_pfelem *pfelem,
														char *len_mod)
{
	char *local_len_mod;

	local_len_mod = twl_strnew(2);
	twl_strcpy(local_len_mod, len_mod);
	if (twl_strequ(local_len_mod, "j") || twl_strequ(local_len_mod, "z"))
		twl_strcpy(local_len_mod, "ll");
	if (pfelem->conv_spec == CONV_SPEC_P
		|| pfelem->conv_spec == CONV_SPEC_O_UP
		|| pfelem->conv_spec == CONV_SPEC_D_UP
		|| pfelem->conv_spec == CONV_SPEC_C_UP
		|| pfelem->conv_spec == CONV_SPEC_S_UP
		|| pfelem->conv_spec == CONV_SPEC_U_UP
		|| pfelem->conv_spec == CONV_SPEC_F_UP
		|| pfelem->conv_spec == CONV_SPEC_F)
		*local_len_mod = '\0';
	return (local_len_mod);
}

void			pfelem_set_length_modifier(t_pfelem *pfelem, char *len_mod)
{
	size_t len;

	len_mod = pfelem_get_harmonized_length_modifier(pfelem, len_mod);
	pfelem->length_modifier_str = twl_strdup(len_mod);
	len = twl_strlen(len_mod);
	if (len == 2)
		pfelem->length_modifier = len_mod[0] * len_mod[1];
	if (len == 1)
		pfelem->length_modifier = *len_mod;
	free(len_mod);
}
