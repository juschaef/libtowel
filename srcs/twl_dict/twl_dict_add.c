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

#include <stdio.h>
#include "twl_dict.h"
#include "twl_string.h"
#include "twl_xstdio.h"

/*
** Mise a la norme, creer une fonction "twl_lst_push_elem_(t_dict *dict,
** t_dict_elem *elem)"
*/

void		twl_dict_add(t_dict *dict, char *key, void *data)
{
	t_dict_elem	*elem;
	t_dict_elem	*tmpelem;

	if (twl_dict_key_exist(dict, key))
	{
		twl_putstr_fd("\n[warning] twl_dict_add: Duplicate entry for key: ", 2);
		twl_putstr_fd(key, 2);
		twl_putstr_fd("\n", 2);
	}
	else
	{
		elem = twl_lst_create_elem__(data);
		elem->key = twl_strdup(key);
		if (!dict->head)
			dict->head = elem;
		else
		{
			tmpelem = dict->head;
			while (tmpelem->next)
				tmpelem = tmpelem->next;
			tmpelem->next = elem;
			twl_lst_link__(tmpelem, tmpelem->next);
		}
	}
}
