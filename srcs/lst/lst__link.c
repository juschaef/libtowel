/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst__link_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:50:11 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 13:04:47 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	twl_lst__link_(t_twl_lst_elem *elem1, t_twl_lst_elem *elem2)
{
	if (elem1)
		elem1->next = elem2;
	if (elem2)
		elem2->prev = elem1;
}
