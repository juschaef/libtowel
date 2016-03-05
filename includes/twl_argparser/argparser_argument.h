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

#ifndef TWL_ARGPARSE_ITEM_H
# define TWL_ARGPARSE_ITEM_H

# include "twl_string.h"
# include "twl_xstdlib.h"
# include "twl_stdio.h"

typedef struct		s_argparser_argument
{
	char			char_key;
	char			*str_key;
	char			*help;
	char			*value;
	int				nargs;
}					t_argparser_argument;

t_argparser_argument		*argparser_argument_new(char char_key, char *str_key, char *help, int nargs);
void				argparser_argument_del(t_argparser_argument *argparser_argument);

#endif
