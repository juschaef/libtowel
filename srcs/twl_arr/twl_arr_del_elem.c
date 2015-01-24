/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_del_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:53:40 by yyang             #+#    #+#             */
/*   Updated: 2015/01/19 14:02:17 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arr.h>
#include <stdlib.h>

void	twl_arr_del_elem(void *twl_arr_, int index)
{
	void **arr;

	arr = twl_arr_;
	arr = arr + index;
	while (*arr)
	{
		*arr = *(arr + 1);
		arr++;
	}
}
