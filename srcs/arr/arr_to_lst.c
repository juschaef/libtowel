/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 22:29:22 by annguyen          #+#    #+#             */
/*   Updated: 2015/01/23 16:35:56 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lst.h>
#include <arr.h>
#include <stdlib.h>

static void		push_to_lst(void *elem, void *lst)
{
	lst_push(lst, elem);
}

t_lst *arr_to_lst(void *arr)
{
	t_lst *lst;

	lst = lst_init();
	arr_iter(arr, push_to_lst, lst);
	return (lst);
}
