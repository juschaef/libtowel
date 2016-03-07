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

#include "twl_argparser/argparser_argument_mgr.h"

static void			print_argparser_argument_fn(void *argparser_argument_,
															void *all_chars_)
{
	t_argparser_argument	*argparser_argument;
	char					*all_chars;

	argparser_argument = argparser_argument_;
	all_chars = all_chars_;
	if (argparser_argument->char_key)
		all_chars[twl_strlen(all_chars)] = argparser_argument->char_key;
}

char				*argparser_argument_mgr_get_all_chars(t_lst *arguments)
{
	char			*all_chars;

	all_chars = twl_strnew(twl_lst_len(arguments));
	twl_lst_iter(arguments, print_argparser_argument_fn, all_chars);
	return (all_chars);
}
