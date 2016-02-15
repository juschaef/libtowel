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

void		twl_dict_set(t_dict *dict, char *key,
												void *data, void (*delfn)())
{
	t_dict_elem	*elem;

	elem = twl_dict_get_elem__(dict, key);
	if (elem != NULL)
	{
		if (delfn)
			delfn(elem->data);
		elem->data = data;
	}
	else
	{
		twl_dict_add(dict, key, data);
	}
}
