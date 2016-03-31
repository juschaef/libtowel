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

static void			build_push_result_item(t_lst *tokens_to_consume,
													t_argparser_result *result)
{
	char					*str_token;

	while ((str_token = twl_lst_pop_front(tokens_to_consume)))
	{
		if (twl_strequ(str_token, "--"))
			break ;
		if (twl_str_starts_with(str_token, "-") && twl_strlen(str_token) >= 2)
		{
			argparser_parse_build_result_item_inner__(str_token, result,
															tokens_to_consume);
			continue ;
		}
		else
		{
			twl_lst_push_back(result->remainders, twl_strdup(str_token));
			break ;
		}
	}
	while ((str_token = twl_lst_pop_front(tokens_to_consume)))
	{
		twl_lst_push_back(result->remainders, twl_strdup(str_token));
	}
}

t_argparser_result	*argparser_parse(t_argparser *this, t_lst *str_tokens)
{
	t_argparser_result	*result;
	t_lst				*str_tokens_copy;

	str_tokens_copy = twl_lst_copy(str_tokens, NULL);
	result = argparser_result_new(this, twl_lst_pop_front(str_tokens_copy));
	build_push_result_item(str_tokens_copy, result);
	twl_lst_del(str_tokens_copy, NULL);
	return (result);
}
