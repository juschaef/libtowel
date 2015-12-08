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

int	twl_lst_reducei(t_lst *lst, int (*fn)(void *data, int memo), int memo)
{
	t_lst_elem__	*elem;

	elem = lst->head;
	while (elem)
	{
		memo = fn(elem->data, memo);
		elem = elem->next;
	}
	return (memo);
}
