/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:24:18 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 21:10:30 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lst.h>
#include <twl_arr.h>
#include <stdlib.h>

#include <stdio.h>

void push_item_to_lst(void *data, void *lst)
{
	lst_push((t_lst *)lst, data);
}

void	lst_sort(t_lst *lst, t_sort_cmp_fn *cmp_fn, void *context)
{
	void **tmp_arr;

	tmp_arr = lst_to_twl_arr_(lst);
	twl_arr_sort(tmp_arr, cmp_fn, context);
	lst_clear(lst, NULL);
	twl_arr_iter(tmp_arr, push_item_to_lst, lst);
	free(tmp_arr);
}
