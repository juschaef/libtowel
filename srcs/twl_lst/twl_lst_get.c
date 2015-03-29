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

/*
** Get by index
** Negative index start at the end.
** e.g.  0 : first elem
**      -1 : last elem
*/

void	*twl_lst_get(t_lst *lst, int index)
{
	t_lst_elem__	*elem;

	elem = twl_lst_get_elem__(lst, index);
	if (elem)
		return (elem->data);
	return (NULL);
}
