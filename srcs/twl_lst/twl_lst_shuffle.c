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

void				twl_lst_shuffle(t_lst *lst)
{
	t_lst			*tmp;

	tmp = twl_lst_new();
	tmp->head = lst->head;
	lst->head = NULL;
	while (twl_lst_len(tmp))
	{
		twl_lst_push_back(lst,
				twl_lst_popi(tmp, twl_lst_indexof(tmp, twl_lst_get_rand(tmp))));
	}
	twl_lst_del(tmp, NULL);
}
