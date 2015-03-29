/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
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
