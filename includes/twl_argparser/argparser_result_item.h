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

#ifndef ARGPARSER_RESULT_ITEM_H
# define ARGPARSER_RESULT_ITEM_H

# include "twl_lst.h"
# include "twl_argparser/argparser_argument.h"

typedef struct				s_argparser_result_item
{
	t_argparser_argument	*argparser_argument;
	char					*option_argument;
}							t_argparser_result_item;

t_argparser_result_item		*argparser_result_item_new(
													t_argparser_argument *this);
void						argparser_result_item_del(
												t_argparser_result_item *this);
void						argparser_result_item_del_void(
												t_argparser_result_item *this);

#endif
