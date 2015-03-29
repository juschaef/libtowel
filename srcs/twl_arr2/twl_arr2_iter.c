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

#include "twl_arr2.h"

void	twl_arr2_iter(void *map_, void (*iter_fn)(void *data, void *context),
																void *context)
{
	int		y;
	int		x;
	void	***map;

	map = map_;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			iter_fn(map[y][x], context);
			x++;
		}
		y++;
	}
}
