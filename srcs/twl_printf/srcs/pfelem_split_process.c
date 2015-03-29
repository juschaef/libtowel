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

void			pfelem_split_process(t_pfelem *pfelem)
{
	pfelem_set_conv_spec(pfelem, pfelem->split[SEG_CONV_SPEC]);
	pfelem_set_length_modifier(pfelem, pfelem->split[SEG_LENGTH_MODIF]);
	pfelem_set_flags(pfelem, pfelem->split[SEG_FLAG]);
	pfelem_set_min_width(pfelem, pfelem->split[SEG_MIN_WIDTH]);
	pfelem_set_precision(pfelem, pfelem->split[SEG_PRECISION]);
}
