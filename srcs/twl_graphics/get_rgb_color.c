/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 21:44:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/02 21:45:30 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_graphics.h"

int		get_rgb_color(int r, int g, int b)
{
	int result;

	result = 0;
	result += r << 16;
	result += g << 8;
	result += b;
	return (result);
}
