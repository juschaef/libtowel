/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr2_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:35:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 15:03:11 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr2.h>

void	twl_arr2_iter(void *map_, void (*iter_fn)(void *data, void *context),
																void *context)
{
	int y;
	int x;
	void ***map;

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
