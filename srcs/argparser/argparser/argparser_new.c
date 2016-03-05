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

#include "twl_argparser/argparser.h"

t_argparser			*argparser_new(t_lst *str_tokens)
{
	t_argparser		*argparser;

	argparser = twl_malloc_x0(sizeof(t_argparser));
	argparser->str_tokens = str_tokens;
	argparser->argparser_items = argparser_item_mgr_new();
	return (argparser);
}
