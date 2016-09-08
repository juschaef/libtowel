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

#include "twl_unistd.h"
#include "twl_xstring.h"
#include "twl_arr.h"
#include <stdlib.h>

char				*g_twl_optarg = NULL;
int					g_twl_opterr = 0;
int					g_twl_optind = 1;
int					g_twl_optopt = 0;

char				*g_twl_optpos = NULL;
char				*g_twl_optpos_save = NULL;
int					g_twl_optsign_active = 0;
int					g_twl_optsign = '-';

static bool			is_start_of_opt(char c)
{
	if (g_twl_optsign_active)
		return (c == '-' || c == '+');
	return (c == '-');
}

static char			handle_optarg(char opt, int argc, char *const argv[],
						const char *optstring)
{
	if (*(g_twl_optpos + 1) == '\0')
	{
		if ((g_twl_optind + 1) < (int)twl_arr_len((char **)argv))
		{
			g_twl_optarg = argv[g_twl_optind + 1];
		}
		else
		{
			opt = (*optstring == ':') ? ':' : '?';
			g_twl_optopt = *g_twl_optpos;
		}
		g_twl_optind += 2;
	}
	else
	{
		g_twl_optarg = g_twl_optpos + 1;
		g_twl_optind += 1;
	}
	return (opt);
	(void)argc;
}

static int			get_opt_char(int argc, char *const argv[],
		const char *optstring)
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

static int			twl_getopt_end_fn(char *cur_arg, int argc,
		char *const argv[], const char *optstring)
{
	if (!g_twl_optpos || !*g_twl_optpos)
	{
		g_twl_optpos_save = twl_strdup(cur_arg);
		g_twl_optpos = g_twl_optpos_save;
	}
	if (is_start_of_opt(*g_twl_optpos))
	{
		g_twl_optsign = *g_twl_optpos;
		g_twl_optpos++;
	}
	if (*g_twl_optpos)
	{
		g_twl_optopt = *g_twl_optpos;
		return (get_opt_char(argc, argv, optstring));
	}
	return (-1);
}

int					twl_getopt(int argc, char *const argv[],
		const char *optstring)
{
	char			*cur_arg;

	if (g_twl_optind == 0)
	{
		g_twl_optind = 1;
		free(g_twl_optpos_save);
		g_twl_optpos_save = NULL;
		g_twl_optpos = NULL;
	}
	g_twl_optopt = 0;
	g_twl_optarg = NULL;
	if (g_twl_optind >= argc)
		return (-1);
	cur_arg = argv[g_twl_optind];
	if (!is_start_of_opt(*cur_arg))
		return (-1);
	if (twl_strequ(cur_arg, "--"))
	{
		g_twl_optind++;
		return (-1);
	}
	return (twl_getopt_end_fn(cur_arg, argc, argv, optstring));
}
