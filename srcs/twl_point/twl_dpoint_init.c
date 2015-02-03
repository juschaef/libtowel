/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dpoint_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/02/02 20:26:36 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_point.h>
#include <stdlib.h>

t_twl_dpoint	*twl_dpoint_init(double x, double y)
{
	t_twl_dpoint *pt;

	pt = malloc(sizeof(t_twl_dpoint));
	pt->x = x;
	pt->y = y;
	return (pt);
}
