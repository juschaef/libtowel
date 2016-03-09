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
#include "twl_lst.h"
#include "twl_arr.h"

static void		push_to_lst(void *elem, void *lst)
{
	twl_lst_push_back(lst, elem);
}

t_lst			*twl_arr_to_lst(void *arr)
{
	t_lst *lst;

	lst = twl_lst_new();
	twl_arr_iter(arr, push_to_lst, lst);
	return (lst);
}
