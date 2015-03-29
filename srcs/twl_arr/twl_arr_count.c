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

size_t	twl_arr_count(void *arr_,
	bool (*filter_fn)(void *elem, void *context), void *context)
{
	size_t	len;
	void	**arr;

	arr = arr_;
	len = 0;
	while (*arr)
	{
		if (filter_fn(*arr, context))
			len++;
		arr++;
	}
	return (len);
}
