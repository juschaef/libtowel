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

char	*pf_conv_str_str(void *val)
{
	char *s;

	s = val;
	if (!s)
		return (twl_strdup(STRING_OF_NULL));
	return (twl_strdup(s));
}

char	*pf_conv_str_char_c(void *val)
{
	return (twl_strdup(val));
}

char	*pf_conv_str_char_hh(void *val)
{
	return (twl_itoa(VOID_PTR_TO(char, val)));
}

char	*pf_conv_str_uchar(void *val)
{
	return (twl_itoa(VOID_PTR_TO(unsigned char, val)));
}

char	*pf_conv_str_return_original(void *val)
{
	return (twl_strdup(val));
}
