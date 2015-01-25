/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_get_elem__.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:30:15 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include <twl_err.h>
#include <assert.h>

t_twl_lst_elem 	*twl_lst_get_elem__(t_lst *lst, int index)
{
	t_twl_lst_elem	*elem;
	size_t len;

	len = twl_lst_len(lst);
	if (index < 0)
		index = (int)len + index;
	elem = lst->head;
	while (elem && index--)
		elem = elem->next;
	return (elem);
}
