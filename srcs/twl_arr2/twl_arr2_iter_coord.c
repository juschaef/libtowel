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

void	twl_arr2_iter_coord(void *arr2_,
		void (*iter_fn)(void *arr2, int y, int x, void *context), void *context)
{
	int		y;
	int		x;
	void	***arr2;

	arr2 = arr2_;
	y = 0;
	while (arr2[y])
	{
		x = 0;
		while (arr2[y][x])
		{
			iter_fn(arr2, x, y, context);
			x++;
		}
		y++;
	}
}
