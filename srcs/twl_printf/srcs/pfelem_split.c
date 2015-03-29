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
