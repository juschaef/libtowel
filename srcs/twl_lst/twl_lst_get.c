/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:49:53 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

/*
** Get by index
** Negative index start at the end.
** e.g.  0 : first elem
**      -1 : last elem
*/

void	*twl_lst_get(t_lst *lst, int index)
{
	t_lst_elem		*elem;

	elem = twl_lst_get_elem__(lst, index);
	if (elem)
		return (elem->data);
	return (NULL);
}
