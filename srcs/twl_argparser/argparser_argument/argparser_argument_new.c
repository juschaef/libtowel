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
#include "twl_argparser/argparser_argument.h"

t_argparser_argument		*argparser_argument_new(char char_key,
													char *str_key,
													char *help,
													int flags)
{
	t_argparser_argument		*this;

	this = twl_malloc_x0(sizeof(t_argparser_argument));
	this->char_key = char_key;
	this->str_key = str_key ? twl_strdup(str_key) : NULL;
	this->help = help ? twl_strdup(help) : NULL;
	this->flags = flags;
	return (this);
}
