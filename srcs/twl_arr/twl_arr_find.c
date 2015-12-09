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

void	*twl_arr_find(void *twl_arr_, bool (*find_fn)(void *arr, void *context),
																void *context)
{
	void **arr;

	arr = twl_arr_;
	while (*arr)
	{
		if (find_fn(*arr, context))
			return (*arr);
		arr++;
	}
	return (NULL);
}
