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

#include "twl_string.h"
#include "twl_arr.h"

void			twl_arr_sort(void *twl_arr_, t_sort_cmp_fn *cmp_fn,
																void *context)
{
	int		i;
	int		j;
	int		size;
	void	**arr;

	i = 0;
	size = twl_arr_len(twl_arr_);
	arr = twl_arr_;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (cmp_fn(arr[j + 1], arr[j], context))
				twl_arr_swap(arr, j + 1, j);
			j++;
		}
		i++;
	}
}
