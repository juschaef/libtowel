/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:17:53 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/14 15:26:55 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>

size_t		twl_lst_count(t_lst *lst, void *(*f)(void *))
{
	int			len;
	t_twl_lst_elem	*elem;

	len = 0;
	elem = lst->head;
	while (elem)
	{
		if (f(elem->data))
			len++;
		elem = elem->next;
	}
	return (len);
}
