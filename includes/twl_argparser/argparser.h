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

#ifndef ARGPARSER_H
# define ARGPARSER_H

# include "twl_argparser/argparser_argument_mgr.h"
# include "twl_argparser/argparser_result.h"

# define ERR_MSG_ILLEGAL_OPTION "illegal option"
# define ERR_MSG_ARGUMENT_REQUIRED "value required"

typedef struct		s_argparser
{
	char			*name;
	char			*usage_text;
	t_lst			*arguments;
}					t_argparser;

t_argparser			*argparser_new(char *name);
void				argparser_del(t_argparser *argparser);

void				argparser_set_usage(t_argparser *this, char *text);

void				argparser_add_argument(t_argparser *this,
													t_argparser_argument *item);
void				argparser_print_help(t_argparser *this);
char				*argparser_get_help_str(t_argparser *this);

t_argparser_result	*argparser_parse(t_argparser *this, t_lst *str_tokens);
t_argparser_result	*argparser_parse_from_arr(t_argparser *this,
													char **str_tokens_arr);

void				argparser_parse_build_result_item_inner__(char *str_token,
													t_argparser_result *result,
													t_lst *tokens_to_consume);
void				argparser_parse_build_argument__(char *key,
													t_argparser_result *result,
													t_lst *tokens_to_consume);

#endif
