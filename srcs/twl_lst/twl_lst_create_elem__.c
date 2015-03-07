/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_create_elem__.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:18:33 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:45:09 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_lst.h"

t_lst_elem__	*twl_lst_create_elem__(void *data)
{
	t_lst_elem__ *elem;

	elem = (t_lst_elem__ *)malloc(sizeof(t_lst_elem__));
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	elem->key = NULL;
	return (elem);
}
