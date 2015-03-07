/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:24:18 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:58:46 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

size_t	twl_lst_len(t_lst *lst)
{
	int				len;
	t_lst_elem__	*elem;

	elem = lst->head;
	len = 0;
	while (elem)
	{
		elem = elem->next;
		len++;
	}
	return (len);
}
