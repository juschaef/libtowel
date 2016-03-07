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

#ifndef ARGPARSER_RESULT_H
# define ARGPARSER_RESULT_H

# include "twl_argparser/argparser_result_item.h"

typedef struct			s_argparser_result
{
	struct s_argparser	*argparser;
	char				*command_name;
	t_lst				*result_items;
	char				*err_msg;
	t_lst				*remainders;
}						t_argparser_result;

struct s_argparser;

t_argparser_result		*argparser_result_new(struct s_argparser *argparser,
															char *command_name);
void					argparser_result_del(
										t_argparser_result *argparser_result);

t_argparser_result_item	*argparser_result_find_item_by_key(
										t_argparser_result *this, char *key);

bool					argparser_result_opt_is_set(t_argparser_result *this,
																	char *key);
char					*argparser_result_opt_get_arg(t_argparser_result *this,
																	char *key);

void					argparser_result_add(
								t_argparser_result *argparser_result,
								t_argparser_result_item *argparser_result_item);

void					argparser_result_print_debug(t_argparser_result *this);
void					argparser_result_print_error_with_help(
													t_argparser_result *this);

#endif
