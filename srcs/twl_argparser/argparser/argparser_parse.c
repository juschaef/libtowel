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



static void			build_push_result_item_inner(char *str_token, t_argparser_result *result, int hyphens)
{
	t_argparser_argument	*argument;
	t_argparser_result_item *result_item;

	if (result->err_msg)
		return ;
	argument = argparser_argument_mgr_find_by_key(result->argparser->arguments, str_token + hyphens);
	if (argument)
	{
		result_item = argparser_result_item_new(argument);
		twl_lst_push_back(result->result_items, result_item);
	}
	else
	{
		twl_asprintf(&(result->err_msg), "illegal option: %s", str_token);
	}
}

static void			build_push_result_item_iter_fn(void *str_token_, void *result_)
{
	t_argparser_result *result;
	char					*str_token;
	int						hyphens;

	result = result_;
	str_token = str_token_;
	hyphens = 0;
	while (*(str_token + hyphens) == '-')
		hyphens++;
	if (hyphens > 0)
	{
		build_push_result_item_inner(str_token, result, hyphens);
	}
	else
	{
		twl_lst_push(result->remainders, str_token);
	}
}

t_argparser_result	*argparser_parse(t_argparser *this, t_lst *str_tokens)
{
	t_argparser_result *result;
	t_lst			*str_tokens_copy;

	str_tokens_copy = twl_lst_copy(str_tokens, NULL);
	result = argparser_result_new(this, twl_lst_pop_front(str_tokens_copy));
	twl_lst_iter(str_tokens_copy, build_push_result_item_iter_fn, result);
	twl_lst_del(str_tokens_copy, NULL);
	return (result);
}
