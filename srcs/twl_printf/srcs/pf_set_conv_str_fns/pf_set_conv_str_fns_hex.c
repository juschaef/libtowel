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

char	*pf_conv_str_hex_uc(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned char, val), 16);
	return (s);
}

char	*pf_conv_str_hex_us(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned short int, val), 16);
	return (s);
}

char	*pf_conv_str_hex(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned int, val), 16);
	return (s);
}

char	*pf_conv_str_hex_uc_up(void *val)
{
	return (twl_strupcase(pf_conv_str_hex_uc(val)));
}

char	*pf_conv_str_hex_us_up(void *val)
{
	return (twl_strupcase(pf_conv_str_hex_us(val)));
}
