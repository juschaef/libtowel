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

#ifndef TWL_ARGPARSE_H
# define TWL_ARGPARSE_H

# include "twl_argparser/argparser_argument_mgr.h"

typedef struct		s_argparser
{
	char			*name;
	t_lst			*arguments;
}					t_argparser;

t_argparser			*argparser_new(char *name);
void				argparser_del(t_argparser *argparser);

void				argparser_add_argument(t_argparser *this, t_argparser_argument *item);
void				argparser_print_help(t_argparser *this);
char				*argparser_get_help_str(t_argparser *this);

#endif
