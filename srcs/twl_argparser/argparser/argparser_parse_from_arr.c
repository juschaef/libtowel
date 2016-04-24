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
#include "twl_arr.h"
#include "twl_xstdio.h"
#include "twl_argparser/argparser.h"
#include "twl_argparser/argparser_result.h"

t_argparser_result	*argparser_parse_from_arr(t_argparser *this,
													char **str_tokens_arr)
{
	t_argparser_result	*result;
	t_lst				*str_tokens;

	str_tokens = twl_arr_to_lst(str_tokens_arr);
	result = argparser_parse(this, str_tokens);
	twl_lst_del(str_tokens, NULL);
	return (result);
}
