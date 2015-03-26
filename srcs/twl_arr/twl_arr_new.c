/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:09:03 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 11:41:22 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_arr.h"
#include "twl_xstdlib.h"

void	*twl_arr_new(size_t size)
{
	void **arr;

	arr = twl_malloc_x0(sizeof(void *) * (size + 1));
	arr[0] = NULL;
	return ((void *)arr);
}
