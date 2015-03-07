/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_get_elem__.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/06 16:31:21 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "twl_lst.h"

t_lst_elem	*twl_lst_get_elem__(t_lst *lst, int index)
{
	t_lst_elem	*elem;
	size_t			len;

	len = twl_lst_len(lst);
	if (index < 0)
		index = (int)len + index;
	elem = lst->head;
	while (elem && index--)
		elem = elem->next;
	return (elem);
}
