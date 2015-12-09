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

char	*pf_conv_str_llong(void *val)
{
	return (twl_lltoa(VOID_PTR_TO(long long, val)));
}

char	*pf_conv_str_octal_ull(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned long long, val), 8);
	return (s);
}

char	*pf_conv_str_ull(void *val)
{
	return (twl_llutoa(VOID_PTR_TO(unsigned long long, val)));
}

char	*pf_conv_str_hex_ull(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned long long, val), 16);
	return (s);
}

char	*pf_conv_str_hex_ull_up(void *val)
{
	return (twl_strupcase(pf_conv_str_hex_ull(val)));
}
