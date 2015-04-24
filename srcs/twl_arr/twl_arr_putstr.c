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
#include "twl_stdio.h"
#include "twl_xstdio.h"

void				twl_arr_putstr(void *arr_, char *sep)
{
	size_t			i;
	size_t			len;
	void			**arr;

	arr = arr_;
	len = twl_arr_len(arr);
	i = 0;
	while (arr[i])
	{
		twl_putstr(arr[i]);
		if (i != (len - 1))
			twl_putstr(sep);
		i++;
	}
}
