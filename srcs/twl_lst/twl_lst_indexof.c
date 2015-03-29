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

#include "twl_lst.h"

int					twl_lst_indexof(t_lst *lst, void *target)
{
	t_lst_elem__	*elem;
	int				i;

	elem = lst->head;
	i = 0;
	while (elem)
	{
		if (elem->data == target)
			return (i);
		elem = elem->next;
		i++;
	}
	return (-1);
}
