/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_get_rand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/01 17:10:05 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_lst.h"
#include "twl_xstdlib.h"

void	*twl_lst_get_rand(t_lst *lst)
{
	t_twl_lst_elem	*elem;
	size_t			len;
	int				random;

	len = twl_lst_len(lst);
	random = twl_randint(0, len - 1);
	elem = twl_lst_get_elem__(lst, random);
	if (elem)
		return (elem->data);
	return (NULL);
}
