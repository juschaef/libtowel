/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_unshift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:29:17 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 14:16:32 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"

void	twl_lst_unshift(t_lst *lst, void *data)
{
	t_twl_lst_elem *elem;

	elem = twl_lst_create_elem__(data);
	twl_lst_link__(elem, lst->head);
	lst->head = elem;
}
