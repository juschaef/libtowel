/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_split_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:14:05 by yyang             #+#    #+#             */
/*   Updated: 2015/01/13 15:27:36 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

void			pfelem_split_process(t_pfelem *pfelem)
{
	pfelem_set_conv_spec(pfelem, pfelem->split[SEG_CONV_SPEC]);
	pfelem_set_length_modifier(pfelem, pfelem->split[SEG_LENGTH_MODIF]);
	pfelem_set_flags(pfelem, pfelem->split[SEG_FLAG]);
	pfelem_set_min_width(pfelem, pfelem->split[SEG_MIN_WIDTH]);
	pfelem_set_precision(pfelem, pfelem->split[SEG_PRECISION]);
}
