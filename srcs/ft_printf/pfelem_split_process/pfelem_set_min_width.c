/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_set_min_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:04:41 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 18:13:10 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

void			pfelem_set_min_width(t_pfelem *pfelem, char *raw)
{
	pfelem->min_width = pfelem_get_value_or_wildcard(raw,
		MIN_WIDTH_WILDCARD_VAL,
		pfelem->min_width);
}
