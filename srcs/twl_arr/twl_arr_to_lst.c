/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_to_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 22:29:22 by annguyen          #+#    #+#             */
/*   Updated: 2015/03/02 11:41:31 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_lst.h"
#include "twl_arr.h"

static void		push_to_lst(void *elem, void *lst)
{
	twl_lst_push(lst, elem);
}

t_lst			*twl_arr_to_lst(void *arr)
{
	t_lst *lst;

	lst = twl_lst_new();
	twl_arr_iter(arr, push_to_lst, lst);
	return (lst);
}
