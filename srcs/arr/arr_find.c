/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:08:08 by yyang             #+#    #+#             */
/*   Updated: 2015/01/21 19:42:23 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>

void *arr_find(void *arr_, int (*find_fn)(void *arr, void *context), void *context)
{
	void **arr;

arr = arr_;
	while (*arr)
	{
		if (find_fn(*arr, context))
			return (*arr);
		arr++;
	}
	return (NULL);
}
