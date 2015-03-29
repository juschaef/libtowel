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

#define VOID_PTR_TO(type, value) *((type *)(value))

char	*pf_conv_str_wstr(void *val)
{
	if (!val)
		return (twl_strdup(STRING_OF_NULL));
	return (twl_wstr_to_str((wchar_t *)(val)));
}

char	*pf_conv_str_wchar(void *val)
{
	return (twl_wstr_to_str((wchar_t *)(val)));
}

char	*pf_conv_str_hex_up(void *val)
{
	return (twl_strupcase(pf_conv_str_hex(val)));
}

char	*pf_conv_str_hex_ul_up(void *val)
{
	return (twl_strupcase(pf_conv_str_hex_long(val)));
}

char	*pf_conv_str_unsign(void *val)
{
	return (twl_lltoa(VOID_PTR_TO(unsigned int, val)));
}
