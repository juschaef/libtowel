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

static void			set_err_msg(char *msg, char *str_token,
													t_argparser_result *result)
{
	twl_asprintf(&(result->err_msg), "%s: %s", msg, str_token);
}

static bool			is_valid_opt(char *str_token)
{
	if (twl_str_starts_with(str_token, "--") && twl_strlen(str_token) == 3)
		return (false);
	return (true);
}

static void			build_argument_one_hyphen_case(char *str_token,
													t_argparser_result *result,
													t_lst *tokens_to_consume)
{
	char			*tmp_token;
	char			*char_token;

	char_token = twl_strnew(1);
	tmp_token = str_token + 1;
	while (*tmp_token)
	{
		if (result->err_msg)
			break ;
		*char_token = *tmp_token;
		argparser_parse_build_argument__(char_token, result, tokens_to_consume);
		tmp_token++;
	}
	free(char_token);
}

void				argparser_parse_build_result_item_inner__(char *str_token,
													t_argparser_result *result,
													t_lst *tokens_to_consume)
{
	if (result->err_msg)
		return ;
	if (!is_valid_opt(str_token))
	{
		set_err_msg(ERR_MSG_ILLEGAL_OPTION, str_token, result);
		return ;
	}
	if (twl_str_starts_with(str_token, "--"))
	{
		argparser_parse_build_argument__(str_token + 2, result,
															tokens_to_consume);
	}
	else if (twl_str_starts_with(str_token, "-"))
	{
		build_argument_one_hyphen_case(str_token, result, tokens_to_consume);
	}
}
