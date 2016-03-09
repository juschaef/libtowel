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
		twl_lst_push_back(new_lst, elem->data);
		begin++;
		elem = elem->next;
	}
	return (new_lst);
}
