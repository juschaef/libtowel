/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_shift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/07 13:58:56 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "twl_lst.h"

void	*twl_lst_shift(t_lst *lst)
{
	t_twl_lst_elem	*elem;
	void			*data;

	elem = lst->head;
	data = elem->data;
	lst->head = elem->next;
	twl_lst_del_elem__(lst, elem, NULL);
	return (data);
}
