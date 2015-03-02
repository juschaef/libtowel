/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:08:08 by yyang             #+#    #+#             */
/*   Updated: 2015/02/26 17:12:52 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_arr.h"

static void	push_to_arr(void *data, void *new_arr)
{
	twl_arr_push(new_arr, data);
}

void		*twl_arr_cpy(void *arr)
{
	void **new_arr;

	new_arr = twl_arr_new(twl_arr_len(arr));
	twl_arr_iter(arr, push_to_arr, new_arr);
	return (new_arr);
}
