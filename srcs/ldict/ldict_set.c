/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldict_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 20:44:39 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ldict.h>
#include <libft.h>

void		ldict_set(t_lst *lst, char *key, void *data, void (*delfn)())
{
	t_lst_elem	*elem;

	elem = ldict_get_elem(lst, key);
	if (elem != NULL)
	{
		delfn(elem->data);
		elem->data = data;
	}
	else
		ldict_add(lst, key, data);
}
