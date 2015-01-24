/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldict_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 19:40:50 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ldict.h>
#include <libft.h>

void		*ldict_get(t_lst *lst, char *key)
{
	t_lst_elem	*elem;

	elem = lst->elems;
	while (elem)
	{
		if (ft_strcmp(elem->key, key) == 0)
			return (elem->data);
		elem = elem->next;
	}
	return (NULL);
}
