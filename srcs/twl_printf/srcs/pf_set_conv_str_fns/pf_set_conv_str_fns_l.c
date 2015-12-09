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

char	*pf_conv_str_long(void *val)
{
	return (twl_lltoa(VOID_PTR_TO(long, val)));
}

char	*pf_conv_str_octal_long(void *val)
{
	return (twl_llutobasestr(VOID_PTR_TO(long, val), 8));
}

char	*pf_conv_str_uoctal_long(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned long, val), 8);
	return (s);
}

char	*pf_conv_str_unsign_long(void *val)
{
	return (twl_llutoa(VOID_PTR_TO(unsigned long, val)));
}

char	*pf_conv_str_hex_long(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned long, val), 16);
	return (s);
}
