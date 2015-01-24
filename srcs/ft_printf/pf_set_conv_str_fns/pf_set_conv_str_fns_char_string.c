/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_conv_str_fns_char_string.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:00:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/07 20:43:14 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#define VOID_PTR_TO(type, value) *((type *)(value))

char *pf_conv_str_str(void *val)
{
	char *s;

	s = val;
	if (!s)
		return (ft_strdup(STRING_OF_NULL));
	return (ft_strdup(s));
}

char *pf_conv_str_char_c(void *val)
{
	return (free_val(ft_strdup(val), val));
}

char *pf_conv_str_char_hh(void *val)
{
	return (free_val(ft_itoa(VOID_PTR_TO(char, val)), val));
}

char *pf_conv_str_uchar(void *val)
{
	return (free_val(ft_itoa(VOID_PTR_TO(unsigned char, val)), val));
}

char *pf_conv_str_return_original(void *val)
{
	return (ft_strdup(val));
}
