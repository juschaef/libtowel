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

#ifndef TWL_UNISTD_H
# define TWL_UNISTD_H

# include <unistd.h>

ssize_t				read(int fildes, void *buf, size_t nbyte);

/*
** getopt
*/

extern char			*g_twl_optarg;
extern int			g_twl_opterr;
extern int			g_twl_optind;
extern int			g_twl_optopt;
extern char			*g_twl_optpos;
extern int			g_twl_optsign_active;
extern int			g_twl_optsign;

int					twl_getopt(int argc, char *const argv[],
					const char *optstring);

/*
** ...
*/

#endif
