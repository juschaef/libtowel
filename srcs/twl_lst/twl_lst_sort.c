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
#include "twl_lst.h"
#include "twl_arr.h"

static void		push_item_to_lst(void *data, void *lst)
{
	twl_lst_push_back((t_lst *)lst, data);
}

void			twl_lst_sort(t_lst *lst, t_sort_cmp_fn *cmp_fn, void *context)
{
	void **tmp_arr;

	tmp_arr = twl_lst_to_arr(lst);
	twl_arr_sort(tmp_arr, cmp_fn, context);
	twl_lst_clear(lst, NULL);
	twl_arr_iter(tmp_arr, push_item_to_lst, lst);
	free(tmp_arr);
}
