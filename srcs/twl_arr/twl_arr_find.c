/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:08:08 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:30:51 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>

void *twl_arr_find(void *twl_arr_, int (*find_fn)(void *arr, void *context),
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
