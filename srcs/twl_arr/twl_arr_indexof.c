/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_indexof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:09:03 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:31:40 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>

/*
** return -1 if not found
*/

int		twl_arr_indexof(void *twl_arr_, void *target)
{
	void	**arr;
	int		i;

	i = 0;
	arr = twl_arr_;
	while (arr[i])
	{
		if (arr[i] == target)
			return (i);
		i++;
	}
	return (-1);
}
