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

#include <stdlib.h>
#include "twl_printf.h"
#include "twl_arr.h"

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
	elem->values = twl_arr_new(MAX_VA_LIST_ELEM);
	elem->raw = s;
	elem->str = NULL;
	elem->prefix = twl_strnew(0);
	elem->c_is_null_char = 0;
	elem->split = twl_arr_new(SEG_COUNT);
	elem->length_modifier_str = NULL;
	return (elem);
}
