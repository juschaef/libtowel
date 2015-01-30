/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_get_elem__.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:07:35 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include <assert.h>

t_twl_lst_elem	*twl_lst_get_elem__(t_lst *lst, int index)
{
	t_twl_lst_elem	*elem;
	size_t			len;

	len = twl_lst_len(lst);
	if (index < 0)
		index = (int)len + index;
	elem = lst->head;
	while (elem && index--)
		elem = elem->next;
	return (elem);
}
