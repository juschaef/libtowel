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

static bool			find_fn(void *result_item_, void *char_ptr_)
{
	t_argparser_result_item	*result_item;
	char					*char_ptr;

	char_ptr = char_ptr_;
	result_item = result_item_;
	return (result_item->argparser_argument->char_key == *char_ptr);
}

bool				argparser_result_char_opt_is_set(t_argparser_result *this, char c)
{
	return ((bool)twl_lst_find(this->result_items, find_fn, &c));
}
