/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 18:10:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/23 21:08:19 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>
#include <arr.h>
#include <stdlib.h>

static void		push_to_arr(void *data, void *arr)
{
	twl_arr_push(arr, data);
}

void **lst_to_twl_arr_(t_lst *lst)
{
	void **arr;

	arr = twl_arr_init(lst_len(lst));
	lst_iter(lst, push_to_arr, arr);
	return (arr);
}
