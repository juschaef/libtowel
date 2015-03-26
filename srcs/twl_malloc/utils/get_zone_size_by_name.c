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

#include <unistd.h>
#include <stddef.h>

#include "twl_xstring.h"

#include "twl_malloc.h"

#define TWL_MALLOC_PAGESIZE 4096

size_t				get_zone_size_by_name(char *name)
{
	if (twl_strequ(name, ZONE_NAME_TINY))
		return (CONST_N_UP_PAGES * TWL_MALLOC_PAGESIZE);
	else if (twl_strequ(name, ZONE_NAME_SMALL))
		return (CONST_M_UP_PAGES * TWL_MALLOC_PAGESIZE);
	return (0);
}
