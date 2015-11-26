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

#include "twl_color.h"
#include "twl_xstdio.h"

void				twl_debug_main_end(void)
{
	twl_lprintf("\n");
	twl_lprintf(C_CYAN);
	twl_lprintf("====================================================\n");
	twl_lprintf("END MAIN\n");
	twl_lprintf("====================================================\n");
	twl_lprintf(C_CLEAR);
}
