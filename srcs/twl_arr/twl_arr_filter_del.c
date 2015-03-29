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
#include "twl_printf.h"

void	*twl_arr_filter_del(void *arr_, bool (*filter_fn)
			(void *data, void *context), void *context, void (*delfn)(void *))
{
	void	**arr;
	void	**filtered_arr;
	int		i;

	arr = arr_;
	filtered_arr = twl_arr_new(twl_arr_count(arr, filter_fn, context));
	i = 0;
	while (arr[i])
	{
		if (filter_fn(arr[i], context))
			twl_arr_push(filtered_arr, arr[i]);
		else if (delfn)
			delfn(arr[i]);
		i++;
	}
	if (delfn)
		free(arr);
	return (filtered_arr);
}
