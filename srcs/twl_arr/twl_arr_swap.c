/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:08:08 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:35:34 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_arr.h"

void	twl_arr_swap(void *twl_arr_, int i, int j)
{
	void *tmp;
	void **arr;

	arr = twl_arr_;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
