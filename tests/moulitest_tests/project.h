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

#ifndef PROJECT_H
# define PROJECT_H

# define _GNU_SOURCE

# include <fw.h>
# include "twl_string.h"
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include "twl_lst.h"
# include "twl_unistd.h"
# include "twl_xstring.h"
# include "twl_arr.h"


char	map_test(char c);
char	mapi_test(unsigned int i, char c);
void	it_test(char *c);
void	iti_test(unsigned int i, char *c);

char			*get_opt_testable_result(
	int (getopt_fn)(int argc, char * const argv[], const char *optstring),
	int				*optind_ptr,
	int				*optopt_ptr,
	char			**optarg_ptr,
	char *argv_str, char *optstring);

#endif
