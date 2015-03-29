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
#include "twl_string.h"

t_dict_elem		*twl_dict_get_elem__(t_dict *dict, char *key)
{
	t_dict_elem	*elem;

	elem = dict->head;
	while (elem)
	{
		if (twl_strcmp(elem->key, key) == 0)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
