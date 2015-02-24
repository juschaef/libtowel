/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:53 by yyang             #+#    #+#             */
/*   Updated: 2015/02/24 18:46:07 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_string.h>
#include <twl_xstdio.h>
#include <stdio.h>

/*
** Mise a la norme, creer une fonction "twl_lst_push_elem_(t_twl_dict *dict,
** t_twl_dict_elem *elem)"
*/

void		twl_dict_add(t_twl_dict *dict, char *key, void *data)
{
	t_twl_dict_elem	*elem;
	t_twl_dict_elem	*tmpelem;

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
