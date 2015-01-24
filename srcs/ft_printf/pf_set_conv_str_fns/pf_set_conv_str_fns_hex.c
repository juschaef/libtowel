/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_conv_str_fns_hex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/07 21:27:59 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

#define VOID_PTR_TO(type, value) *((type *)(value))

char *pf_conv_str_hex_uc(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned char, val), 16);
	return (free_val(s, val));
}

char *pf_conv_str_hex_us(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned short int, val), 16);
	return (free_val(s, val));
}

char *pf_conv_str_hex(void *val)
{
	char *s;

	s = twl_llutobasestr(VOID_PTR_TO(unsigned int, val), 16);
	return (free_val(s, val));
}

char *pf_conv_str_hex_uc_up(void *val)
{
	return (twl_strupcase(pf_conv_str_hex_uc(val)));
}

char *pf_conv_str_hex_us_up(void *val)
{
	return (twl_strupcase(pf_conv_str_hex_us(val)));
}
