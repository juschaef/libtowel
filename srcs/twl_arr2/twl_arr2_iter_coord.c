/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr2_iter_coord.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:35:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 22:03:31 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr2.h>

void	twl_arr2_iter_coord(void *arr2_, void (*iter_fn)(void *arr2, int y, int x, void *context), void *context)
{
	int y;
	int x;
	void ***arr2;

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
