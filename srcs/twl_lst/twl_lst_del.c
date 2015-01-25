/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 14:59:25 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include <stdlib.h>

void	twl_lst_del(t_lst *lst, void (*delfn)(void *))
{
	t_twl_lst_elem *elem;

	elem = lst->head;
	while (elem)
	{
		twl_lst_del_elem__(lst, elem, delfn);
		elem = elem->next;
	}
	free(lst);
}
