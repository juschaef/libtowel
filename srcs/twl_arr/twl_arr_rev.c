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

#include "twl_arr.h"

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
