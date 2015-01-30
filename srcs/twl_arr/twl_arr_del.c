/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:41:44 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:29:30 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>
#include <stdlib.h>

void	twl_arr_del(void *twl_arr_)
{
	void	**arr;
	size_t	size;
	size_t	i;

	arr = twl_arr_;
	size = twl_arr_len(arr);
	i = 0;
	while (i < size)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
