/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldict_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 19:42:40 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ldict.h>
#include <libft.h>

void		ldict_add(t_lst *lst, char *key, void *data)
{
	t_lst_elem	*elem;
	t_lst_elem	*tmpelem;

	if (ldict_get(lst, key))
	{
		twl_putstr_fd("\n[warning] ldict_add: Duplicate entry for key: ", 2);
		twl_putstr_fd(key, 2);
		twl_putstr_fd("\n", 2);
	}
	else
	{
		elem = lst_create_elem_(data);
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
			lst__link_(tmpelem, tmpelem->next);
		}
	}

}
