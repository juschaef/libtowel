/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:24:18 by yyang             #+#    #+#             */
/*   Updated: 2015/03/06 18:43:42 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "twl_lst.h"
#include "twl_arr.h"

static void		push_item_to_lst(void *data, void *lst)
{
	twl_lst_push((t_lst *)lst, data);
}

void			twl_lst_swap(t_lst *lst, int i, int j)
{
	void **tmp_arr;

	tmp_arr = twl_lst_to_arr(lst);
	twl_arr_swap(tmp_arr, i, j);
	twl_lst_clear__(lst, NULL);
	twl_arr_iter(tmp_arr, push_item_to_lst, lst);
	free(tmp_arr);
}
