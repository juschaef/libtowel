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

#include "twl_xunistd.h"

#include "twl_stdio.h" // remove this

char				*g_twl_optarg = NULL;
int					g_twl_opterr = 0;
int					g_twl_optind = 1;
int					g_twl_optopt = 0;

static char			*g_getopt_pos;

int					twl_getopt(int argc, char * const argv[],
					const char *optstring)
{
	char			opt;
	char			*arg;

	if (g_twl_optind >= argc)
		return (-1);
	arg = argv[g_twl_optind];
	if (g_twl_optind == 1)
		g_getopt_pos = arg;
	if (!*g_getopt_pos)
		g_getopt_pos = arg;
	if (*arg != '-')
		return (-1);
	if (*g_getopt_pos == '-')
		g_getopt_pos++;
	if (*g_getopt_pos)
	{
		opt = *g_getopt_pos;
		g_getopt_pos++;
		if (!*g_getopt_pos)
			g_twl_optind++;
		return (opt);
	}
	(void)argc;
	(void)argv;
	(void)optstring;
	return (-1);
}
