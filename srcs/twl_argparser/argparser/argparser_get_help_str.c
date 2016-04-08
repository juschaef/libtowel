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

static void			print_argparser_argument_fn(void *argument_,
																void *help_str_)
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
	char			*help_str_tmp;
	char			*option_chars;

	option_chars = argparser_argument_mgr_get_all_chars(this->arguments);
	twl_asprintf(&help_str, "usage: %s", this->name);
	if (this->usage_text)
	{
		help_str = twl_strjoinfree(help_str, " ", 'l');
		help_str = twl_strjoinfree(help_str, this->usage_text, 'l');
	}
	else if (twl_strlen(option_chars))
	{
		help_str_tmp = help_str;
		twl_asprintf(&help_str, "%s [-%s]", help_str_tmp, option_chars);
		free(help_str_tmp);
	}
	help_str = twl_strjoinfree(help_str, "\n", 'l');
	twl_lst_iter(this->arguments, print_argparser_argument_fn, &help_str);
	free(option_chars);
	return (help_str);
}
