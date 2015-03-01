/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr2_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:35:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/03/01 17:21:30 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr2.h>
#include <twl_arr.h>
#include <stdlib.h>

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
