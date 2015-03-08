/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:17:53 by juschaef          #+#    #+#             */
/*   Updated: 2015/03/08 21:36:43 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

size_t	twl_lst_count(t_lst *lst, void *(*condition_fn)(void *, void *context)
															, void *context)
{
	int				len;
	t_lst_elem__	*elem;

	len = 0;
	elem = lst->head;
	while (elem)
	{
		if (condition_fn(elem->data, context))
			len++;
		elem = elem->next;
	}
	return (len);
}
