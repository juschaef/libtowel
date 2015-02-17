/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:41:44 by yyang             #+#    #+#             */
/*   Updated: 2015/02/17 18:01:07 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>
#include <stdlib.h>

static void del_fn_wrapper(void *elem, void *del_fn_)
{
	void (*del_fn)(void *elem);

	del_fn = del_fn_;
	del_fn(elem);
}

void		twl_arr_del(void *arr, void (*del_fn)(void *elem))
{
	twl_arr_iter(arr, del_fn_wrapper, del_fn);
	free(arr);
}
