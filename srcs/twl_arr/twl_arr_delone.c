/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:53:40 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 21:59:20 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>
#include <stdlib.h>

void	twl_arr_delone(void *twl_arr_, int index)
{
	void **arr;

	arr = twl_arr_;
	arr = arr + index;
	while (*arr)
	{
		*arr = *(arr + 1);
		arr++;
	}
	*(arr - 1) = NULL;
}
