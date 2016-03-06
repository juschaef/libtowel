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
#include "twl_argparser/argparser_result.h"

t_argparser_result			*argparser_result_new(t_argparser *argparser)
{
	t_argparser_result		*this;

	this = twl_malloc_x0(sizeof(t_argparser_result));
	this->argparser = argparser;
	this->result_items = twl_lst_new();
	this->err_msg = NULL;
	return (this);
}
