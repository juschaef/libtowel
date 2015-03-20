/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/11 16:52:09 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "twl_lst.h"
#include "twl_xstdio.h"

void	twl_lst_insert(t_lst *lst, int index, void *data)
{
	t_lst_elem__ *elem;
	t_lst_elem__ *elem_new;

	if (index == 0)
		twl_lst_unshift(lst, data);
	else if (index >= (int)twl_lst_len(lst))
		twl_putstr_fd("\n[warning] Index does not exist !\n", 2);
	else
	{
		elem = twl_lst_get_elem__(lst, index);
		elem_new = twl_lst_create_elem__(data);
		if (!elem_new)
			return ;
		twl_lst_link3__(elem->prev, elem_new, elem);
	}
}
