/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/03/07 15:36:31 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"
#include "twl_printf.h"

void	twl_dict_iter(t_lst *lst,
	void (*f)(char *key, void *data, void *context), void *context)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		f(elem->key, elem->data, context);
		elem = next;
	}
}
