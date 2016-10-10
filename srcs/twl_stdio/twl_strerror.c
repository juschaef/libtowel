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

#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "twl_stdio.h"
#include "twl_string.h"

static char		g_twl_strerror_msg[1024];

char			*twl_strerror(int errnum)
{
	const char	**tab;
	int			size;

	tab = (const char **)sys_errlist;
	size = sys_nerr;
	if (errnum < 0 || errnum > size || !tab[errnum])
	{
		twl_sprintf(g_twl_strerror_msg, "Unknown error %i%c", errnum, 0);
	}
	else
	{
		twl_strcpy(g_twl_strerror_msg, tab[errnum]);
	}
	return (g_twl_strerror_msg);
}
