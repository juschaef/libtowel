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

#include "twl_arr.h"

static void	push_to_arr(void *data, void *new_arr)
{
	twl_arr_push(new_arr, data);
}

void		*twl_arr_cpy(void *arr)
{
	void **new_arr;

	new_arr = twl_arr_new(twl_arr_len(arr));
	twl_arr_iter(arr, push_to_arr, new_arr);
	return (new_arr);
}
