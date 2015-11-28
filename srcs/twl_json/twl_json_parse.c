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

#include "twl_json.h"

#include "twl_xstring.h"

#include "twl_stdio.h"

t_jnode			*twl_json_parse(char *json_str)
{
	return NULL;
	(void)json_str;
}

/*
	[true,[false,true],false]

	parent = none
	while (str)
		if { [
			node = build_node(TYPE_OBJECT)
			parent = node
			str += 1;
			continue
		if } ]
			parent = parent.parent
			node = parent
			close
		if string, bool, ...
			node = build_node(...)
			parent.push_node(node)
			i += len
			continue
		if ,
			str++;
			continue
		else
			error
*/
