/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:41:44 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 11:23:28 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <stdlib.h>

void	arr_del(void *arr_)
{
	void **arr;
	size_t size;
	size_t i;

	arr = arr_;
	size = arr_len(arr);
	i = 0;
	while (i < size)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
