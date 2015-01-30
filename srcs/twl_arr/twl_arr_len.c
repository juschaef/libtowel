/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 12:23:16 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:32:48 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_arr.h>

size_t	twl_arr_len(void *twl_arr_)
{
	size_t	size;
	void	**arr;

	arr = twl_arr_;
	size = 0;
	while (arr[size])
		size++;
	return (size);
}
