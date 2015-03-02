/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:41:44 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 11:41:00 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_arr.h"

static void del_fn_wrapper(void *elem, void *del_fn_)
{
	void (*del_fn)(void *elem);

	del_fn = del_fn_;
	if (del_fn)
		del_fn(elem);
}

void		twl_arr_del(void *arr, void (*del_fn)(void *elem))
{
	twl_arr_iter(arr, del_fn_wrapper, del_fn);
	free(arr);
}
