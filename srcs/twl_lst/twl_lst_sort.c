/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:24:18 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:00:56 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <twl_lst.h>
#include <twl_arr.h>
#include <stdlib.h>

#include <stdio.h>

void	push_item_to_lst(void *data, void *lst)
{
	twl_lst_push((t_lst *)lst, data);
}

void	twl_lst_sort(t_lst *lst, t_sort_cmp_fn *cmp_fn, void *context)
{
	void **tmp_arr;

	tmp_arr = twl_lst_to_arr__(lst);
	twl_arr_sort(tmp_arr, cmp_fn, context);
	twl_lst_clear__(lst, NULL);
	twl_arr_iter(tmp_arr, push_item_to_lst, lst);
	free(tmp_arr);
}
