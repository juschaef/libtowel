/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_slice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 09:41:52 by yyang             #+#    #+#             */
/*   Updated: 2015/03/11 16:52:33 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "twl_lst.h"
#include "twl_xstdio.h"

t_lst						*twl_lst_slice(t_lst *lst, int begin, int end)
{
	t_lst			*new_lst;
	t_lst_elem__	*elem;
	size_t			len;

	new_lst = twl_lst_new();
	elem = twl_lst_get_elem__(lst, begin);
	len = twl_lst_len(lst);
	if (end > (int)len)
		twl_putstr_fd("\n[warning] Index error !\n", 2);
	while (begin < end)
	{
		twl_lst_push(new_lst, elem->data);
		begin++;
		elem = elem->next;
	}
	return (new_lst);
}
