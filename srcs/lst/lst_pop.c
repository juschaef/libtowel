/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 18:53:49 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>
#include <assert.h>

void	twl_lst_pop(t_lst *lst, void (*f)())
{
	t_twl_lst_elem *elem;
	t_twl_lst_elem *prev;

	elem = lst->elems;
	while (elem->next)
		elem = elem->next;
	prev = elem->prev;
	lstelem_del(elem, f);
	if (lst->elems == elem)
		lst->elems = NULL;
	if (prev)
		prev->next = NULL;
}
