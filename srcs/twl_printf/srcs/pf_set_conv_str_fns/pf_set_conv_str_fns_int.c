/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_conv_str_fns_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/07 20:44:04 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

#define VOID_PTR_TO(type, value) *((type *)(value))

char *pf_conv_str_int(void *val)
{
	return (twl_itoa(VOID_PTR_TO(int, val)));
}

char *pf_conv_str_short(void *val)
{
	return (twl_itoa(VOID_PTR_TO(short int, val)));
}

char *pf_conv_str_ushort(void *val)
{
	return (twl_itoa(VOID_PTR_TO(unsigned short int, val)));
}

char *pf_conv_str_octal_us(void *val)
{
	return (twl_llutobasestr(VOID_PTR_TO(unsigned int, val), 8));
}

char *pf_conv_str_octal(void *val)
{
	return (twl_llutobasestr(VOID_PTR_TO(unsigned int, val), 8));
}
