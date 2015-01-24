/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:41:44 by yyang             #+#    #+#             */
/*   Updated: 2015/01/14 10:40:33 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <stdlib.h>

/*
** warning: NOT WORKING
*/

void	*arr_cpy(void *arr)
{
	long	*arr_tmp;
	long	*new_arr;
	int		i;

	arr_tmp = (long *)arr;
	new_arr = (long *)malloc(sizeof(arr_tmp) * (arr_len(arr_tmp) + 1));
	i = 0;
	while (arr_tmp[i])
	{
		new_arr[i] = arr_tmp[i];
		i++;
	}
	new_arr[i] = 0;
	return (new_arr);
}
