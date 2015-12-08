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

static void	del_fn_wrapper(void *elem, void *del_fn_)
{
	void (*del_fn)(void *elem);

	del_fn = del_fn_;
	if (del_fn)
		del_fn(elem);
}

void		twl_arr_del(void *arr, void (*del_fn)(void *elem))
{
	twl_arr_iter(arr, del_fn_wrapper, del_fn);
	free(arr);
}
