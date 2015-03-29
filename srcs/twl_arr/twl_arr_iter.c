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
