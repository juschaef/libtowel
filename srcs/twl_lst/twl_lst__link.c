/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst__link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:50:11 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 19:49:57 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

void	twl_lst_link__(t_lst_elem *elem1, t_lst_elem *elem2)
{
	if (elem1)
		elem1->next = elem2;
	if (elem2)
		elem2->prev = elem1;
}
