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

static void			build_push_result_item(t_lst *tokens_to_consume, t_argparser_result *result)
{
	char					*str_token;
	bool					double_hyphen_occurred;

	double_hyphen_occurred = false;
	while ((str_token = twl_lst_pop_front(tokens_to_consume)))
	{
		if (double_hyphen_occurred)
		{
			twl_lst_push(result->remainders, twl_strdup(str_token));
			continue ;
		}
		if (twl_strequ(str_token, "--"))
		{
			double_hyphen_occurred = true;
			continue ;
		}
		if (twl_str_starts_with(str_token, "-"))
		{
			argparser_parse_build_result_item_inner__(str_token, result, tokens_to_consume);
			continue ;
		}
		twl_lst_push(result->remainders, twl_strdup(str_token));
	}
}

t_argparser_result	*argparser_parse(t_argparser *this, t_lst *str_tokens)
{
	t_argparser_result	*result;
	t_lst				*str_tokens_copy;

	str_tokens_copy = twl_lst_copy(str_tokens, NULL);
	result = argparser_result_new(this);
	build_push_result_item(str_tokens_copy, result);
	twl_lst_del(str_tokens_copy, NULL);
	return (result);
}
