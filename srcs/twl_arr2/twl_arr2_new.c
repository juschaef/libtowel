/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr2_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:35:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 16:11:58 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <twl_arr2.h>
#include <twl_xstdlib.h>

void	***twl_arr2_new(int rows, int cols, void *(*new_fn)(int y, int x, void *context),
																void *context)
{
	int y;
	int x;
	void ***map;

	map = twl_malloc_x0(sizeof(void **) * (rows + 1));
	y = 0;
	while (y < rows)
	{
		x = 0;
		map[y] = twl_malloc_x0(sizeof(void **) * (cols + 1));
		while (x < cols)
		{
			map[y][x] = new_fn(y, x, context);
			x++;
		}
		map[y][x] = NULL;
		y++;
	}
	map[y] = NULL;
	return (map);
}
