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

char				*g_twl_optarg;
int					g_twl_opterr = 0;
int					g_twl_optind = 1;
int					g_twl_optopt = 0;

int					twl_getopt(int argc, char * const argv[],
					const char *optstring)
{
	char			**tmp_av;
	char			opt;

	tmp_av = (char **)argv + g_twl_optind;
	if (!*tmp_av)
		return (-1);
	// twl_printf("tmp_av %s\n", *tmp_av);
	if (*tmp_av[0] == '-')
	{
		g_twl_optind++;
		opt = (*tmp_av)[1];
		// twl_printf("opt %c\n", opt);
		return (opt);
	}
	(void)argc;
	(void)argv;
	(void)optstring;
	return (-1);
}
