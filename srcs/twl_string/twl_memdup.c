/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:06:27 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 11:49:09 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_string.h"

void	*twl_memdup(const void *s, size_t n)
{
	void	*dup;

	if (!s)
		return (NULL);
	dup = malloc(n);
	if (!dup)
		return (NULL);
	twl_memcpy(dup, s, n);
	return (dup);
}
