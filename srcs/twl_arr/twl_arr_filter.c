/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_filter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/02/15 15:09:33 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>
#include <stdio.h> //
#include "twl_printf.h"

void	*twl_arr_filter(void *arr_, t_bool (*filter_fn)
			(void *data, void *context), void *context)
{
	return (twl_arr_filter_del(arr_, filter_fn, context, NULL));
	// void **arr;
	// void **filtered_arr;

	// arr = arr_;
	// filtered_arr = twl_arr_new(twl_arr_count(arr, filter_fn, context));
	// while (*arr)
	// {
	// 	if (filter_fn(*arr, context))
	// 		twl_arr_push(filtered_arr, *arr);
	// 	arr++;
	// }
	// return (filtered_arr);
}
