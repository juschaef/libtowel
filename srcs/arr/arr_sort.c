/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 10:16:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/21 22:43:40 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arr.h>

void			arr_sort(void *arr_, t_sort_cmp_fn *cmp_fn, void *context)
{
	int i;
	int j;
	int size;
	void **arr;

	i = 0;
	size = arr_len(arr_);
	arr = arr_;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (cmp_fn(arr[j + 1], arr[j], context))
				arr_swap(arr, j + 1, j);
			j++;
		}
		i++;
	}
}
