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

#include <stdbool.h>
#include "twl_dict.h"
#include "twl_string.h"

void	*twl_dict_key_from_value(t_dict *dict,
			bool (*find)(void *data, void *value), void *data)
{
	t_dict_elem	*elem;

	elem = dict->head;
	while (elem)
	{
		if (find(elem->data, data))
			return (elem->key);
		elem = elem->next;
	}
	return (NULL);
}
