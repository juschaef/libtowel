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

static bool			is_next_arg_a_invalid_arg(int argc, char * const argv[])
{
	if ((g_twl_optind + 1) >= argc)
		return (true);
	return (twl_arr_len((void *)(argv + g_twl_optind)) <= 2
			&& (*argv[g_twl_optind + 1] == '-'));
}

static char			handle_optarg(char opt, int argc, char * const argv[], const char *optstring)
{
	if (*(g_twl_optpos + 1) == '\0')
	{
		if (is_next_arg_a_invalid_arg(argc, argv))
		{
			opt = (*optstring == ':') ? ':' : '?';
			g_twl_optopt = *g_twl_optpos;
		}
		else
		{
			g_twl_optarg = argv[g_twl_optind + 1];
		}
		g_twl_optind += 2;
		// if (g_twl_optind > argc)
		// 	g_twl_optind = argc;
	}
	else
	{
		g_twl_optarg = g_twl_optpos + 1;
		g_twl_optind += 1;
	}
	return (opt);
}

static int			get_opt_char(int argc, char * const argv[], const char *optstring)
{
	char			opt;
	char			*found;

	if ((found = twl_strchr(optstring, *g_twl_optpos)))
	{
		opt = *g_twl_optpos;
		if (*(found + 1) == ':')
		{
			opt = handle_optarg(opt, argc, argv, optstring);
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
		return (get_opt_char(argc, argv, optstring));
	}
	return (-1);
}
