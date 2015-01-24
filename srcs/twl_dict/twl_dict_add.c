/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:29:43 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_string.h>
#include <twl_xstdio.h>

/*
** Mise a la norme, creer une fonction "twl_lst_push_elem_(t_lst *lst, t_twl_lst_elem *elem)"
*/

void		twl_dict_add(t_lst *lst, char *key, void *data)
{
	t_twl_lst_elem	*elem;
	t_twl_lst_elem	*tmpelem;

	if (twl_dict_get(lst, key))
	{
		twl_putstr_fd("\n[warning] twl_dict_add: Duplicate entry for key: ", 2);
		twl_putstr_fd(key, 2);
		twl_putstr_fd("\n", 2);
	}
	else
	{
		elem = twl_lst_create_elem_(data);
		elem->parent = lst;
		elem->key = twl_strdup(key);
		if (!lst->elems)
		{
			lst->elems = elem;
		}
		else
		{
			tmpelem = lst->elems;
			while (tmpelem->next)
				tmpelem = tmpelem->next;
			tmpelem->next = elem;
			twl_lst_link_(tmpelem, tmpelem->next);
		}
	}
}