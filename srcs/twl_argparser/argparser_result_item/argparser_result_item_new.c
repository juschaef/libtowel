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

#include "twl_xstdlib.h"
#include "twl_argparser/argparser_result_item.h"

t_argparser_result_item			*argparser_result_item_new(
									t_argparser_argument *argparser_argument)
{
	t_argparser_result_item		*this;

	this = twl_malloc_x0(sizeof(t_argparser_result_item));
	this->argparser_argument = argparser_argument;
	this->option_argument = NULL;
	return (this);
}
