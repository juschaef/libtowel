/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 18:10:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/30 16:01:13 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_lst.h"
#include "twl_arr.h"

static void		push_to_arr(void *data, void *arr)
{
	twl_arr_push(arr, data);
}

void			**twl_lst_to_arr(t_lst *lst)
{
	void **arr;

	arr = twl_arr_new(twl_lst_len(lst));
	twl_lst_iter(lst, push_to_arr, arr);
	return (arr);
}
