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

void			pfelem_free(t_pfelem *elem)
{
	free(elem->str);
	free(elem->prefix);
	twl_arr_del(elem->split, free);
	free(elem->raw);
	twl_arr_del(elem->values, free);
	if (elem->length_modifier_str)
		free(elem->length_modifier_str);
	free(elem->conv_spec_str);
	free(elem);
}
