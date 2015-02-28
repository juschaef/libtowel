/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_key_exist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:34 by yyang             #+#    #+#             */
/*   Updated: 2015/02/28 18:29:03 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_string.h>
#include <stdbool.h>

bool twl_dict_key_exist(t_twl_dict *dict, char *key)
{
	t_twl_dict_elem	*elem;

	elem = dict->head;
	while (elem)
	{
		if (twl_strcmp(elem->key, key) == 0)
			return (true);
		elem = elem->next;
	}
	return (false);
}
