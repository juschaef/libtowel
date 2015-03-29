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

#include <stdlib.h>
#include "twl_arr2.h"
#include "twl_arr.h"

static void		*new_fn(int y, int x, void *arr_original_)
{
	void		***arr_original;
	size_t		rows;

	arr_original = arr_original_;
	rows = twl_arr_len(arr_original);
	return (arr_original[rows - x - 1][y]);
}

static void		*twl_arr2_rotate_one(void *arr_)
{
	void ***arr_original;
	void ***arr_new;

	arr_original = arr_;
	arr_new = (void ***)twl_arr2_new(twl_arr_len(arr_original[0]),
						twl_arr_len(arr_original), new_fn, arr_original);
	return (arr_new);
}

void			*twl_arr2_rotate(void *original_arr, int times)
{
	void ***newarr;
	void ***tmp;

	times %= 4;
	if (!times)
		times = 4;
	newarr = twl_arr2_rotate_one(original_arr);
	times--;
	while (times--)
	{
		tmp = newarr;
		newarr = twl_arr2_rotate_one(newarr);
		twl_arr2_del(tmp, NULL);
		(void)tmp;
	}
	return (newarr);
}
