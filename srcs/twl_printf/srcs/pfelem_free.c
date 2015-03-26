/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:14:05 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 21:07:59 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_printf.h"
#include "twl_arr.h"

void			pfelem_free(t_pfelem *elem)
{
	twl_free(elem->str);
	twl_free(elem->prefix);
	twl_arr_del(elem->split, free);
	twl_free(elem->raw);
	twl_arr_del(elem->values, free);
	if (elem->length_modifier_str)
		twl_free(elem->length_modifier_str);
	twl_free(elem->conv_spec_str);
	twl_free(elem);
}
