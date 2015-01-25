/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:13:31 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

static void		pfelem_process_do(t_pfelem *pfelem)
{
	if (*(pfelem->raw) == '%')
	{
		pfelem_split_build(pfelem);
		pfelem_split_process(pfelem);
	}
	else
		pfelem->str = twl_strdup(pfelem->raw);
}

void			pfelem_split(t_pfelem *pfelem)
{
	pfelem_process_do(pfelem);
}
