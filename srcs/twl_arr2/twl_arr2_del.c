/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr2_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:35:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 20:46:03 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>
#include <stdlib.h>

static void		free_fn(void *arr, void *del_fn)
{
	twl_arr_del(arr, del_fn);
}

void			twl_arr2_del(void *arr2, void (*del_fn)(void *elem))
{
	twl_arr_iter(arr2, free_fn, del_fn);
	free(arr2);
}
