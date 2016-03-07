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
#include "twl_stdio.h"
#include "twl_argparser/argparser.h"

char				*argparser_argument_get_keys_ast_str(
												t_argparser_argument *argument)
{
	char			*keys;
	char			*option_argument;

	keys = NULL;
	if (argument->flags & ARGP_HAS_OPTION_ARGUMENT)
		option_argument = " arg";
	else
		option_argument = "";
	if (argument->char_key && argument->str_key)
		twl_asprintf(&keys, "-%c%s, --%s%s", argument->char_key,
												option_argument,
												argument->str_key,
												option_argument);
	else if (argument->char_key)
		twl_asprintf(&keys, "-%c%s", argument->char_key, option_argument);
	else if (argument->str_key)
		twl_asprintf(&keys, "--%s%s", argument->str_key, option_argument);
	else
		keys = twl_strdup("");
	return (keys);
}
