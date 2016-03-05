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

typedef struct		s_argparser_item
{
	char			char_key;
	char			*str_key;
	char			*help;
	char			*value;
}					t_argparser_item;

t_argparser_item		*argparser_item_new(char char_key, char *str_key, char *help);
void				argparser_item_del(t_argparser_item *argparser_item);

#endif
