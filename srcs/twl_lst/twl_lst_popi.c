/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_popi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/06 22:03:09 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include <assert.h>
#include "twl_lst.h"

void	*twl_lst_popi(t_lst *lst, int index)
{
	t_lst_elem__	*elem;
	void			*data;

	elem = twl_lst_get_elem__(lst, index);
	data = elem->data;
	twl_lst_del_elem__(lst, elem, NULL);
	if (lst->head == elem)
		lst->head = NULL;
	return (data);
}
