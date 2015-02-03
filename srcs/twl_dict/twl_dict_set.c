/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:21:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:44:00 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_dict.h>
#include <twl_string.h>

void		twl_dict_set(t_twl_dict *dict, char *key, void *data, void (*delfn)())
{
	t_twl_dict_elem	*elem;

	elem = twl_dict_get_elem__(dict, key);
	if (elem != NULL)
	{
		delfn(elem->data);
		elem->data = data;
	}
	else
	{
		twl_dict_add(dict, key, data);
	}
}
