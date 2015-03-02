/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 12:17:36 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 18:11:00 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_string.h"

/*
** print string 's' to file descriptor 'fd'
*/

void		*twl_realloc(void *ptr, size_t size)
{
	void	*dup;

	if (!(dup = malloc(size)))
		return (NULL);
	twl_memcpy(dup, ptr, size);
	free(ptr);
	return (dup);
}
