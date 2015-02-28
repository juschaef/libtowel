/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_randint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:02:23 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 18:57:30 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

int		twl_randint(int start, int end)
{
	srand(time(NULL));
	return (rand() % (end + 1 - start) + start);
}