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

#define ERR_MSG_ILLEGAL_OPTION "illegal option"
#define ERR_MSG_ARGUMENT_REQUIRED "argument required"

static void			set_err_msg(char *msg, char *str_token, t_argparser_result *result)
{
	twl_asprintf(&(result->err_msg), "%s: %s", msg, str_token);
}

static bool			is_valid_opt(char *str_token)
{
	if (twl_str_starts_with(str_token, "-") && twl_strlen(str_token) == 2)
		return (true);
	if (twl_str_starts_with(str_token, "--") && twl_strlen(str_token) > 3)
		return (true);
	return (false);
}

static void			handle_has_option_argument(char *str_token, t_argparser_result_item	*result_item, t_argparser_result *result, t_lst *tokens_to_consume)
{
	if (result_item->argparser_argument->flags & ARGP_HAS_OPTION_ARGUMENT)
	{
		if (twl_lst_len(tokens_to_consume)
			&& !twl_str_starts_with(twl_lst_first(tokens_to_consume), "-"))
			result_item->option_argument = twl_strdup(twl_lst_pop_front(tokens_to_consume));
		else
			set_err_msg(ERR_MSG_ARGUMENT_REQUIRED, str_token, result);
	}
}

void				argparser_parse_build_result_item_inner__(char *str_token, t_argparser_result *result, t_lst *tokens_to_consume)
{
	t_argparser_argument	*argument;
	t_argparser_result_item	*result_item;
	int						hyphens_to_skip;

	if (result->err_msg)
		return ;
	if (!is_valid_opt(str_token))
	{
		set_err_msg(ERR_MSG_ILLEGAL_OPTION, str_token, result);
		return ;
	}
	hyphens_to_skip = twl_str_starts_with(str_token, "--") ? 2 : 1;
	argument = argparser_argument_mgr_find_by_key(result->argparser->arguments, str_token + hyphens_to_skip);
	if (argument)
	{
		result_item = argparser_result_item_new(argument);
		twl_lst_push_back(result->result_items, result_item);
		handle_has_option_argument(str_token, result_item, result, tokens_to_consume);
	}
	else
	{
		set_err_msg(ERR_MSG_ILLEGAL_OPTION, str_token, result);
	}
}
