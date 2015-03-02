/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_get_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:41:59 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_dict.h"
#include "twl_string.h"

t_twl_dict_elem		*twl_dict_get_elem__(t_twl_dict *dict, char *key)
{
	t_twl_dict_elem	*elem;

	elem = dict->head;
	while (elem)
	{
		if (twl_strcmp(elem->key, key) == 0)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
