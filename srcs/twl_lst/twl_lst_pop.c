/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/12 11:49:18 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include <assert.h>
#include "twl_lst.h"

void	*twl_lst_pop(t_lst *lst)
{
	t_lst_elem__	*elem;
	void			*data;

	elem = lst->head;
	assert(elem);
	while (elem->next)
		elem = elem->next;
	data = elem->data;
	twl_lst_del_elem__(lst, elem, NULL);
	if (lst->head == elem)
		lst->head = NULL;
	return (data);
}
