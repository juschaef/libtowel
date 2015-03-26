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

#include "twl_xstring.h"
#include "twl_color.h"
#include "twl_malloc.h"

void				print_colored_by_name(char *name)
{
	if (twl_strequ(name, ZONE_NAME_TINY))
		twl_putstr(C_CYAN);
	else if (twl_strequ(name, ZONE_NAME_SMALL))
		twl_putstr(C_GREEN);
	else
		twl_putstr(C_BLUE);
	twl_putstr("===> ");
	twl_putstr(name);
	twl_putstr(C_CLEAR);
}
