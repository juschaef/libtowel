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

char	*pf_conv_str_int(void *val)
{
	return (twl_itoa(VOID_PTR_TO(int, val)));
}

char	*pf_conv_str_short(void *val)
{
	return (twl_itoa(VOID_PTR_TO(short int, val)));
}

char	*pf_conv_str_ushort(void *val)
{
	return (twl_itoa(VOID_PTR_TO(unsigned short int, val)));
}

char	*pf_conv_str_octal_us(void *val)
{
	return (twl_llutobasestr(VOID_PTR_TO(unsigned int, val), 8));
}

char	*pf_conv_str_octal(void *val)
{
	return (twl_llutobasestr(VOID_PTR_TO(unsigned int, val), 8));
}
