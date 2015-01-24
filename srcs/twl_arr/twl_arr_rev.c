/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 12:27:25 by yyang             #+#    #+#             */
/*   Updated: 2015/01/14 13:42:45 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>

void	*twl_arr_rev(void *arr)
{
	int				j;
	int				i;
	long			*l_arr;
	long			a;
	size_t			len;

	l_arr = (long *)arr;
	len = twl_arr_len(l_arr);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		a = l_arr[i];
		l_arr[i] = l_arr[j];
		l_arr[j] = a;
		i++;
		j--;
	}
	return (l_arr);
}
