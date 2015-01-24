/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 22:18:04 by yyang             #+#    #+#             */
/*   Updated: 2015/01/15 13:08:17 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_point.h>
#include <stdlib.h>
#include <mlx.h>

t_ft_point	*ft_point_init(int x, int y)
{
	t_ft_point *pt;

	pt = malloc(sizeof(t_ft_point));
	pt->x = x;
	pt->y = y;
	return (pt);
}
