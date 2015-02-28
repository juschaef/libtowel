/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr2_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:35:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 21:05:34 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr2.h>
#include <twl_arr.h>
#include <stdio.h> //

static void *new_fn(int y, int x, void *arr_original_)
{
	void ***arr_original;
	size_t rows;

	arr_original = arr_original_;
	rows = twl_arr_len(arr_original);
	return (arr_original[rows - x - 1][y]);
}

void	*twl_arr2_rotate(void *arr_, int times)
{
	void ***arr_original;
	void ***arr_new;

	arr_original = arr_;
	arr_new = (void ***)twl_arr2_new(twl_arr_len(arr_original[0]),
						twl_arr_len(arr_original), new_fn, arr_original);
	(void)times;
	return (arr_new);
}
