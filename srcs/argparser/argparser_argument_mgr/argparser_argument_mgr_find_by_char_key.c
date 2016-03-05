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

#include "twl_color.h"
#include "twl_argparser/argparser_argument_mgr.h"

static bool			find_fn(void *argument_, void *char_ptr_)
{
	t_argparser_argument	*argument;
	char					*char_ptr;

	char_ptr = char_ptr_;
	argument = argument_;
	return (argument->char_key == *char_ptr);
}

t_argparser_argument *argparser_argument_mgr_find_by_char_key(t_lst *arguments, char c)
{
	return (twl_lst_find(arguments, find_fn, &c));
}
