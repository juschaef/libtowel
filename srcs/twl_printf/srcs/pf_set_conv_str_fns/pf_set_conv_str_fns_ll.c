/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_conv_str_fns_ll.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/07 21:30:12 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

#define VOID_PTR_TO(type, value) *((type *)(value))

char *pf_conv_str_llong(void *val)
{
	return (freevl(twl_lltoa(VOID_PTR_TO(long long, val)), val));
}

char *pf_conv_str_octal_ull(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned long long, val), 8);
	return (freevl(s, val));
}

char *pf_conv_str_ull(void *val)
{
	return (freevl(twl_llutoa(VOID_PTR_TO(unsigned long long, val)), val));
}

char *pf_conv_str_hex_ull(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned long long, val), 16);
	return (freevl(s, val));
}

char *pf_conv_str_hex_ull_up(void *val)
{
	return (twl_strupcase(pf_conv_str_hex_ull(val)));
}
