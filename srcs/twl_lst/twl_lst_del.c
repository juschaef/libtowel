/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:52:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/31 16:15:58 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_lst.h"

void	twl_lst_del(t_lst *lst, void (*delfn)(void *))
{
	t_lst_elem *elem;
	t_lst_elem *next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		twl_lst_del_elem__(lst, elem, delfn);
		elem = next;
	}
	free(lst);
}
