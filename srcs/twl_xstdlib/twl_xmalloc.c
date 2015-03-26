/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_xmalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 18:55:21 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/06 18:55:33 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"

void	*twl_xmalloc(int size)
{
	char *new;

	new = (char *)malloc(size);
	if (!new)
		exit(1);
	return (new);
}
