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

static void			set_illegal_option(char *str_token, t_argparser_result *result)
{
	twl_asprintf(&(result->err_msg), "illegal option: %s", str_token);
}

static bool			is_valid_opt(char *str_token)
{
	if (twl_str_starts_with(str_token, "-") && twl_strlen(str_token) == 2)
		return (true);
	if (twl_str_starts_with(str_token, "--") && twl_strlen(str_token) > 3)
		return (true);
	return (false);
}

static void			build_push_result_item_inner(char *str_token, t_argparser_result *result)
{
	t_argparser_argument	*argument;
	int						hyphens_to_skip;

	if (result->err_msg)
		return ;
	if (!is_valid_opt(str_token))
	{
		set_illegal_option(str_token, result);
		return ;
	}
	hyphens_to_skip = twl_str_starts_with(str_token, "--") ? 2 : 1;
	argument = argparser_argument_mgr_find_by_key(result->argparser->arguments, str_token + hyphens_to_skip);
	if (argument)
		twl_lst_push_back(result->result_items, argparser_result_item_new(argument));
	else
		set_illegal_option(str_token, result);
}

static void			build_push_result_item_iter_fn(void *str_token_, void *result_, void *double_hyphen_occurred_ptr_)
{
	t_argparser_result *result;
	char					*str_token;
	bool					*double_hyphen_occurred_ptr;

	result = result_;
	str_token = str_token_;
	double_hyphen_occurred_ptr = double_hyphen_occurred_ptr_;
	if (*double_hyphen_occurred_ptr)
	{
		twl_lst_push(result->remainders, str_token);
		return ;
	}
	if (twl_strequ(str_token, "--"))
	{
		*double_hyphen_occurred_ptr = true;
		return ;
	}
	if (twl_str_starts_with(str_token, "-"))
	{
		build_push_result_item_inner(str_token, result);
		return ;
	}
	twl_lst_push(result->remainders, str_token);
}

t_argparser_result	*argparser_parse(t_argparser *this, t_lst *str_tokens)
{
	t_argparser_result	*result;
	t_lst				*str_tokens_copy;
	bool				double_hyphen_occurred;

	double_hyphen_occurred = false;
	str_tokens_copy = twl_lst_copy(str_tokens, NULL);
	result = argparser_result_new(this, twl_lst_pop_front(str_tokens_copy));
	twl_lst_iter2(str_tokens_copy, build_push_result_item_iter_fn, result, &double_hyphen_occurred);
	twl_lst_del(str_tokens_copy, NULL);
	return (result);
}
