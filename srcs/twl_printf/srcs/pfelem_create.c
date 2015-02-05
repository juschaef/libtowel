/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/02/05 21:11:59 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>
#include <stdlib.h>

t_pfelem	*pfelem_create(char *s)
{
	t_pfelem *elem;

	elem = malloc(sizeof(t_pfelem));
	elem->flags = 0;
	elem->min_width = 0;
	elem->precision = PRECISION_NOT_SET;
	elem->length_modifier = 0;
	elem->conv_spec = 0;
	elem->conv_spec_str = NULL;
	elem->values[0] = NULL;
	elem->raw = s;
	elem->str = NULL;
	elem->prefix = twl_strnew(0);
	elem->c_is_null_char = 0;
	twl_bzero(elem->split, 5);
	return (elem);
}
