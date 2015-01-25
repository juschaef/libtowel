/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_get_elem__.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 15:59:37 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

t_twl_lst_elem 	*twl_lst_get_elem__(t_lst *lst, int index)
{
	t_twl_lst_elem	*elem;

	if (index < 0)
		index = (int)twl_lst_len(lst) + index;
	elem = lst->head;
	while (elem && index--)
		elem = elem->next;
	return (elem ? elem : NULL);
}
