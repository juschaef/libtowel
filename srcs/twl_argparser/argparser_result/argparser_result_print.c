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
#include "twl_argparser/argparser_result.h"
#include "twl_argparser/argparser_result_item.h"

static void			iter_valid_options_fn(void *result_item_)
{
	t_argparser_result_item	*result_item;
	char					*keys;
	char					*option_arguments;

	result_item = result_item_;
	keys = argparser_argument_get_keys_ast_str(result_item->argparser_argument);
	option_arguments = twl_lst_strjoin(result_item->option_arguments, "|");
	twl_printf("  %-30s%s\n", keys, option_arguments);
	free(keys);
	free(option_arguments);
}

static void			print_errors(t_argparser_result *this)
{
	if (this->err_msg)
	{
		twl_printf("ERRORS: %s\n", this->err_msg);
	}
}

void				argparser_result_print(t_argparser_result *this)
{
	twl_printf("valid options:\n");
	twl_lst_iter0(this->result_items, iter_valid_options_fn);
	print_errors(this);
}
