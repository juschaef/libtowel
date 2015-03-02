/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:08:08 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 15:32:18 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_arr.h"

void *twl_arr_last(void *twl_arr_)
{
	int		i;
	void	**arr;

	arr = twl_arr_;
	if (!arr[0])
		return (NULL);
	i = 0;
	while (arr[i + 1])
		i++;
	return (arr[i]);
}
