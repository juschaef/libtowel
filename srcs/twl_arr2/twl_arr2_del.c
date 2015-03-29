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
#include "twl_arr.h"

static void		free_fn(void *arr, void *del_fn)
{
	twl_arr_del(arr, del_fn);
}

void			twl_arr2_del(void *arr2, void (*del_fn)(void *elem))
{
	twl_arr_iter(arr2, free_fn, del_fn);
	free(arr2);
}
