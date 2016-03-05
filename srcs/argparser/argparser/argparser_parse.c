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

#include <stdlib.h>
#include "twl_xstdio.h"
#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

static void			iter_fn(void *str_token_, void *result_)
{
	t_argparser_result *result;
	t_argparser_result_item *result_item;
	t_argparser_argument	*argument;
	char					*str_token;

	result = result_;
	str_token = str_token_;
	if (twl_str_starts_with(str_token, "-"))
	{
		argument = argparser_argument_mgr_find_by_char_key(
			result->argparser->arguments, *(str_token + 1));
		result_item = argparser_result_item_new(argument);
		twl_lst_push_back(result->result_items, result_item);
	}
}

t_argparser_result	*argparser_parse(t_argparser *this, t_lst *str_tokens)
{
	t_argparser_result *result;

	result = argparser_result_new(this);
	twl_lst_iter(str_tokens, iter_fn, result);
	return (result);
}
