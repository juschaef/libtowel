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

#ifndef TWL_XUNISTD_H
# define TWL_XUNISTD_H

#include <unistd.h>

ssize_t				read(int fildes, void *buf, size_t nbyte);

int					twl_execvep(char *file, char **argv, char **envp);
char				*twl_getcwd_str(void);
int					twl_getch(void);

/*
** getopt
*/

extern char			*g_twl_optarg;
extern int			g_twl_opterr;
extern int			g_twl_optind;
extern int			g_twl_optopt;
int					twl_getopt(int argc, char * const argv[],
					const char *optstring);

/*
** ...
*/

#endif
