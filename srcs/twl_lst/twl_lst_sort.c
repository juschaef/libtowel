/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:24:18 by yyang             #+#    #+#             */
/*   Updated: 2015/02/17 18:02:55 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_stdlib.h"
#include "twl_string.h"
#include "twl_lst.h"
#include "twl_arr.h"

static void		push_item_to_lst(void *data, void *lst)
{
	twl_lst_push((t_lst *)lst, data);
}

void			twl_lst_sort(t_lst *lst, t_sort_cmp_fn *cmp_fn, void *context)
{
	void **tmp_arr;

	tmp_arr = twl_lst_to_arr(lst);
	twl_arr_sort(tmp_arr, cmp_fn, context);
	twl_lst_clear__(lst, NULL);
	twl_arr_iter(tmp_arr, push_item_to_lst, lst);
	twl_free(tmp_arr);
}
