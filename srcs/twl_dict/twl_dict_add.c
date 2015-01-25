/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:35:18 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_string.h>
#include <twl_xstdio.h>

/*
** Mise a la norme, creer une fonction "twl_lst_push_elem_(t_dict *dict, t_twl_dict_elem *elem)"
*/

void		twl_dict_add(t_dict *dict, char *key, void *data)
{
	t_twl_dict_elem	*elem;
	t_twl_dict_elem	*tmpelem;

	if (twl_dict_get(dict, key))
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
		{
			dict->head = elem;
		}
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
