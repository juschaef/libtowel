/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_insert_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/08 16:33:06 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include <assert.h>
#include "twl_lst.h"
#include "twl_xstdio.h"

void	twl_lst_insert_lst(t_lst *lst_dest, int index, t_lst *lst_src)
{
	t_lst_elem__ *elem1;
	t_lst_elem__ *elem2;

	elem1 = twl_lst_get_elem__(lst_dest, index);
	elem2 = elem1->prev;
	if (index == 0)
		lst_dest->head = lst_src->head;
	else if (index >= (int)twl_lst_len(lst_dest))
		twl_putstr_fd("\n[warning] Index does not exist !\n", 2);
	else
		twl_lst_link__(elem2, lst_src->head);
	twl_lst_link__(twl_lst_get_elem__(lst_src, -1), elem1);
}
