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

#include "twl_dict.h"
#include "twl_lst.h"

void	twl_dict_delone(t_dict *dict, char *key, void (*delfn)())
{
	t_dict_elem	*elem;

	elem = twl_dict_get_elem__(dict, key);
	twl_lst_link__(elem->prev, elem->next);
	if (!elem->prev)
		dict->head = elem->next;
	twl_lst_del_elem__(dict, elem, delfn);
}
