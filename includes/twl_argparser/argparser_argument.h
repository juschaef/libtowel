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

#ifndef ARGPARSER_ARGUMENT_H
# define ARGPARSER_ARGUMENT_H

# include "twl_string.h"
# include "twl_xstdlib.h"
# include "twl_stdio.h"
# include "twl_lst.h"

enum				e_argparser_argument_options
{
	ARGP_REQUIRED = 0x01,
	ARGP_HAS_OPTION_ARGUMENT = 0x02,
};

typedef struct			s_argparser_argument
{
	char				char_key;
	char				*str_key;
	char				*help;
	int					flags;
}						t_argparser_argument;

t_argparser_argument	*argparser_argument_new(char char_key,
													char *str_key,
													char *help,
													int flags);
void					argparser_argument_del(
									t_argparser_argument *argparser_argument);
void					argparser_argument_del_void(void *this);

bool					argparser_argument_test_by_key(
										t_argparser_argument *this, char *key);
bool					argparser_argument_test_by_key_void(void *this,
																	void *key);

t_argparser_argument	*argparser_argument_mgr_find_by_key(t_lst *arguments,
																	char *key);
char					*argparser_argument_get_keys_ast_str(
												t_argparser_argument *argument);

#endif
