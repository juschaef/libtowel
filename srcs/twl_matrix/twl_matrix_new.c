/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
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
