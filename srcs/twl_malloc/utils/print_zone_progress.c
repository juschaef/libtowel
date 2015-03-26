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

static int			count_fn(void *mseg_, int memo)
{
	t_mseg			*mseg;

	mseg = mseg_;
	return (mseg->size + memo);
}

static void			print_percent_color(int percent)
{
	if (percent == 0)
		percent = 1;
	if (percent > 70)
		twl_putstr(C_RED);
	else if (percent > 50)
		twl_putstr(C_YELLOW);
	else
		twl_putstr(C_GREEN);
	twl_putnbr(percent);
	twl_putstr(" %");
	twl_putstr(C_CLEAR);
}

void				print_zone_progress(t_zone *zone)
{
	int total_size;
	int percent;

	total_size = twl_lst_reducei(zone->msegs, count_fn, 0);
	percent = (total_size * 100.0) / zone->size;
	twl_putstr(" [");
	print_percent_color(percent);
	twl_putstr("]");
	(void)zone;
}
