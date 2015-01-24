/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:09:03 by yyang             #+#    #+#             */
/*   Updated: 2015/01/19 17:32:02 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>

void	twl_arr_iter(void *twl_arr_, void (*f)(void *elem, void *context), void *context)
{
	int i;
	void **arr;

	arr = twl_arr_;
	i = 0;
	while (arr[i])
	{
		f(arr[i], context);
		i++;
	}
}
