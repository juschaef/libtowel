/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "twl_lst.h"

void				*twl_lst_pop_back(t_lst *lst)
{
	t_lst_elem__	*elem;
	void			*data;

	elem = lst->head;
	if (!elem)
		return (NULL);
	while (elem->next)
		elem = elem->next;
	data = elem->data;
	twl_lst_del_elem__(lst, elem, NULL);
	if (lst->head == elem)
		lst->head = NULL;
	return (data);
}
