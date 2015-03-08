/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_link3__.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:50:11 by yyang             #+#    #+#             */
/*   Updated: 2015/03/08 15:26:43 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

void twl_lst_link3__(t_lst_elem__ *elem1, t_lst_elem__ *elem2,
														t_lst_elem__ *elem3)
{
	if (elem1)
		elem1->next = elem2;
	if (elem2)
	{
		elem2->prev = elem1;
		elem2->next = elem3;
	}
	if (elem3)
		elem3->prev = elem2;
}
