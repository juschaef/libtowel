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

#include "twl_stdio.h"
#include "twl_xstring.h"

#include "twl_json.h"

static void			twl_json_dump_array_fn(void *node_,
													void *next, void *output)
{
	t_jnode			*node;

	node = node_;
	twl_json_dump_rec(node, output);
	if (next)
	{
		twl_lst_push(output, JSON_STR_SEP);
	}
}

static void			twl_json_dump_object_fn(char *key, void *node_, void *next,
																 void *output)
{
	t_jnode			*node;

	node = node_;
	if (node->parent->type == JSON_OBJECT)
	{
		twl_lst_push(output, "\"");
		twl_lst_push(output, key);
		twl_lst_push(output, "\":");
	}
	twl_json_dump_rec(node, output);
	if (next)
	{
		twl_lst_push(output, JSON_STR_SEP);
	}
}

static void			twl_push_string(t_lst *output, char *str)
{
	twl_lst_push(output, "\"");
	twl_lst_push(output, str);
	twl_lst_push(output, "\"");
}

void				twl_json_dump_rec(t_jnode *node, t_lst *output)
{
	if (node->type == JSON_ARRAY)
	{
		twl_lst_push(output, "[");
		twl_lst_itern(node->value.array, twl_json_dump_array_fn, output);
		twl_lst_push(output, "]");
	}
	else if (node->type == JSON_OBJECT)
	{
		twl_lst_push(output, "{");
		twl_dict_itern(node->value.object, twl_json_dump_object_fn, output);
		twl_lst_push(output, "}");
	}
	else if (node->type == JSON_NUMBER)
		twl_lst_push(output, twl_itoa(twl_jnode_get_prim(node)));
	else if (node->type == JSON_BOOL)
		twl_lst_push(output, twl_jnode_get_prim(node) ? "true" : "false");
	else if (node->type == JSON_NULL)
		twl_lst_push(output, JSON_STR_NULL);
	else if (node->type == JSON_STRING)
		twl_push_string(output, twl_jnode_get_string(node));
	else
		twl_lst_push(output, "?");
}
