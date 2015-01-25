/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 14:59:30 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include <stdlib.h>
#include <assert.h>

void	twl_lst_pop(t_lst *lst, void (*f)())
{
	t_twl_lst_elem *elem;
	t_twl_lst_elem *prev;

	elem = lst->head;
	while (elem->next)
		elem = elem->next;
	prev = elem->prev;
	twl_lst_del_elem__(lst, elem, f);
	if (lst->head == elem)
		lst->head = NULL;
	if (prev)
		prev->next = NULL;
}
