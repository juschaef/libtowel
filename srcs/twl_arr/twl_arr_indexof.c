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
