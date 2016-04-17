/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "twl_stdio.h"
static void		twl_bzero(void *s, size_t n)
{
	size_t	index;
	char	*temp;

	temp = s;
	index = 0;
	while (index < n)
	{
		temp[index] = 0;
		index++;
	}
}

char			*twl_strnew(size_t size)
{
	char *new;

	// twl_dprintf(2, "twl_strnew 00\n");
	new = (char *)malloc(sizeof(char) * (size + 1));
	// twl_dprintf(2, "twl_strnew 01\n");
	if (!new)
		return (NULL);
	// twl_dprintf(2, "twl_strnew 02\n");
	twl_bzero(new, size + 1);
	// twl_dprintf(2, "twl_strnew 03\n");
	return (new);
}
