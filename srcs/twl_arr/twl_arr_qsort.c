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

#include "twl_string.h"
#include "twl_arr.h"

static int			partition(void **s, int l, int h, t_qsort_cmp_fn *cmp_fn)
{
	int				i;
	int				p;
	int				firsthight;

	p = h;
	firsthight = l;
	i = l;
	while (i < h)
	{
		if (cmp_fn(s[i], s[p]))
		{
			twl_arr_swap(s, i, firsthight);
			firsthight++;
		}
		i++;
	}
	twl_arr_swap(s, p, firsthight);
	return (firsthight);
}

static void			quick_sort(void **s, int l, int h, t_qsort_cmp_fn *cmp_fn)
{
	int				p;

	if ((h - l) > 0)
	{
		p = partition(s, l, h, cmp_fn);
		quick_sort(s, l, p - 1, cmp_fn);
		quick_sort(s, p + 1, h, cmp_fn);
	}
}

void				twl_arr_qsort(void *arr_, t_qsort_cmp_fn *cmp_fn)
{
	void			**arr;
	int				size;

	arr = arr_;
	size = twl_arr_len(arr);
	if (size == 1 || size == 0)
		return ;
	quick_sort(arr, 0, size - 1, cmp_fn);
}
