/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_set_conv_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:04:21 by yyang             #+#    #+#             */
/*   Updated: 2015/01/13 15:50:12 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

void		pfelem_set_conv_spec(t_pfelem *pfelem, char *conv_spec)
{
	pfelem->conv_spec = *conv_spec;
	pfelem->conv_spec_str = twl_strdup(conv_spec);
}
