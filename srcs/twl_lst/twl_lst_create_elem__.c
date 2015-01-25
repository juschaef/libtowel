/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_create_elem__.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:18:33 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:39:32 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_lst.h>
#include <stdlib.h>

t_twl_lst_elem	*twl_lst_create_elem__(void *data)
{
	t_twl_lst_elem *elem;

	elem = (t_twl_lst_elem *)malloc(sizeof(t_twl_lst_elem));
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	elem->key = NULL;
	return (elem);
}
