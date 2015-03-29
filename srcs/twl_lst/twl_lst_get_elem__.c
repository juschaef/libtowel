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

#include <assert.h>
#include "twl_lst.h"

t_lst_elem__	*twl_lst_get_elem__(t_lst *lst, int index)
{
	t_lst_elem__	*elem;
	size_t			len;

	len = twl_lst_len(lst);
	if (index < 0)
		index = (int)len + index;
	elem = lst->head;
	while (elem && index--)
		elem = elem->next;
	return (elem);
}
