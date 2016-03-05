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

# include "twl_argparser/argparser.h"
# include "twl_argparser/argparser_result_item.h"

typedef struct		s_argparser_result
{
	t_argparser 	*argparser;
	t_lst		   	*result_items;
}					t_argparser_result;

t_argparser_result	*argparser_result_new(t_argparser *argparser);
void				argparser_result_del(t_argparser_result *argparser_result);

bool				argparser_result_char_opt_is_set(t_argparser_result *this, char c);


void				argparser_result_add(t_argparser_result *argparser_result,
								t_argparser_result_item *argparser_result_item);

#endif
