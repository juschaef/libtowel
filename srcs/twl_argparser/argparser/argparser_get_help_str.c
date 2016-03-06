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

static void			print_argparser_argument_fn(void *argument_, void *help_str_)
{
	t_argparser_argument	*argument;
	char					*keys;
	char					*line;
	char					**help_str;

	argument = argument_;
	help_str = help_str_;
	keys = argparser_argument_get_keys_ast_str(argument);
	twl_asprintf(&line, "  %-30s%s\n", keys, argument->help);
	*help_str = twl_strjoinfree(*help_str, line, 'b');
	free(keys);
}

char				*argparser_get_help_str(t_argparser *this)
{
	char			*help_str;

	twl_asprintf(&help_str, "usage: %s [-%s]\n", this->name,
						argparser_argument_mgr_get_all_chars(this->arguments));
	twl_lst_iter(this->arguments, print_argparser_argument_fn, &help_str);
	return (help_str);
}
