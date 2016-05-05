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
#include "twl_xstring.h"
#include "twl_arr.h"

#include "twl_stdio.h" // remove this

char				*g_twl_optarg = NULL;
int					g_twl_opterr = 0;
int					g_twl_optind = 1;
int					g_twl_optopt = 0;

static char			*g_twl_optpos = NULL;

static int			get_opt_char(char * const argv[], const char *optstring)
{
	char			opt;
	char			*found;

	if ((found = twl_strchr(optstring, *g_twl_optpos)))
	{
		opt = *g_twl_optpos;
		if (*(found + 1) == ':')
		{

			if (*(g_twl_optpos + 1) == '\0')
			{

				if (twl_arr_len((void *)(argv + g_twl_optind)) <= 2
					&& (*argv[g_twl_optind + 1] == '-'))
				{
					opt = (*optstring == ':') ? ':' : '?';
					g_twl_optopt = *g_twl_optpos;
				}
				else
				{
					g_twl_optarg = argv[g_twl_optind + 1];
				}
				g_twl_optind += 2;
			}
			else
			{
				g_twl_optarg = g_twl_optpos + 1;
				g_twl_optind += 1;
			}
			g_twl_optpos = NULL;
			return (opt);
		}
	}
	else
	{
		g_twl_optopt = *g_twl_optpos;
		opt = '?';
	}
	g_twl_optpos++;
	if (!*g_twl_optpos)
		g_twl_optind++;
	return (opt);
}

int					twl_getopt(int argc, char * const argv[],
					const char *optstring)
{
	char			*cur_arg;

	if (g_twl_optind == 0)
	{
		g_twl_optind = 1;
		g_twl_optpos = NULL;
	}
	g_twl_optopt = 0;
	g_twl_optarg = NULL;
	if (g_twl_optind >= argc)
		return (-1);
	cur_arg = argv[g_twl_optind];
	if (*cur_arg != '-')
		return (-1);
	if (twl_strequ(cur_arg, "--"))
	{
		g_twl_optind++;
		return (-1);
	}
	if (!g_twl_optpos || !*g_twl_optpos)
		g_twl_optpos = cur_arg;
	if (*g_twl_optpos == '-')
		g_twl_optpos++;
	if (*g_twl_optpos)
	{
		g_twl_optopt = *g_twl_optpos;
		return (get_opt_char(argv, optstring));
	}
	return (-1);
}
