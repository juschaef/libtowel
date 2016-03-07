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

static bool				find_fn(void *result_item_, void *key)
{
	t_argparser_result_item	*result_item;

	result_item = result_item_;
	return (argparser_argument_test_by_key(result_item->argparser_argument,
																		key));
}

t_argparser_result_item	*argparser_result_find_item_by_key(
													t_argparser_result *this,
													char *key)
{
	return (twl_lst_find(this->result_items, find_fn, key));
}
