/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:09:03 by yyang             #+#    #+#             */
/*   Updated: 2015/02/15 15:02:00 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>

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
