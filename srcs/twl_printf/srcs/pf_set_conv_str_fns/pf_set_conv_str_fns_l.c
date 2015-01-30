/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_conv_str_fns_l.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/07 21:31:05 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

#define VOID_PTR_TO(type, value) *((type *)(value))

char *pf_conv_str_long(void *val)
{
	return (freevl(twl_lltoa(VOID_PTR_TO(long, val)), val));
}

char *pf_conv_str_octal_long(void *val)
{
	return (freevl(twl_llutobasestr(VOID_PTR_TO(long, val), 8), val));
}

char *pf_conv_str_uoctal_long(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned long, val), 8);
	return (freevl(s, val));
}

char *pf_conv_str_unsign_long(void *val)
{
	return (freevl(twl_llutoa(VOID_PTR_TO(unsigned long, val)), val));
}

char *pf_conv_str_hex_long(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned long, val), 16);
	return (freevl(s, val));
}
