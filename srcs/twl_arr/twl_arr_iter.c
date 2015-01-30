/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:09:03 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:32:03 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>

void	twl_arr_iter(void *twl_arr_, void (*f)(void *elem, void *context),
																void *context)
{
	int		i;
	void	**arr;

	arr = twl_arr_;
	i = 0;
	while (arr[i])
	{
		f(arr[i], context);
		i++;
	}
}
