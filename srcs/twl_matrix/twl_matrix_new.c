/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_matrix_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 21:53:13 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 14:51:21 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_arr.h"

void	*twl_matrix_new(int *a)
{
	void	**arr;
	int		i;

	i = 0;
	arr = twl_arr_new(*a);
	if (*a > 0)
	{
		while (i < *a)
		{
			arr[i] = twl_matrix_new(++a);
			i++;
		}
	}
	return (arr);
}
