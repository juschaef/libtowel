/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_cat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/08 16:39:09 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include <assert.h>
#include "twl_lst.h"
#include "twl_xstdio.h"

void	twl_lst_cat(t_lst *lst_dest, t_lst *lst_src)
{
	t_lst_elem__ *elem;

	elem = twl_lst_get_elem__(lst_dest, -1);
	if (!elem)
		lst_dest->head = lst_src->head;
	else
		twl_lst_link__(elem, lst_src->head);
}
