/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_get_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 18:47:26 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

t_twl_lst_elem 	*twl_lst_get_(t_lst *lst, size_t index)
{
	t_twl_lst_elem	*elem;

	elem = lst->elems;
	while (elem && index--)
		elem = elem->next;
	return (elem ? elem : NULL);
}
