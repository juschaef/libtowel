/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_point_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:02:47 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_point.h>
#include <stdlib.h>

t_twl_point	*twl_point_init(int x, int y)
{
	t_twl_point *pt;

	pt = malloc(sizeof(t_twl_point));
	pt->x = x;
	pt->y = y;
	return (pt);
}
