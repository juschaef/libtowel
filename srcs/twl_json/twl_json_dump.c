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

#include "twl_json.h"

#include "twl_xstring.h"

#include "twl_stdio.h"

static void			twl_json_dump_rec(t_jnode *node, t_lst *output);

static void			twl_json_dump_one(void *node_, void *next, void *output)
{
	t_jnode			*node;

	node = node_;
	twl_json_dump_rec(node, output);
	if (next)
	{
		twl_lst_push(output, JSON_SEP_CHAR);
	}
}

static void			twl_json_dump_object(char *key, void *node_, void *next,
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
		twl_lst_push(output, JSON_SEP_CHAR);
	}
}

static void			twl_json_dump_rec(t_jnode *node, t_lst *output)
{
	if (node->type == JSON_ARRAY)
	{
		twl_lst_push(output, "[");
		twl_lst_itern(node->value.array, twl_json_dump_one, output);
		twl_lst_push(output, "]");
	}
	else if (node->type == JSON_OBJECT)
	{
		twl_lst_push(output, "{");
		twl_dict_itern(node->value.object, twl_json_dump_object, output);
		twl_lst_push(output, "}");
	}
	else if (node->type == JSON_NUMBER)
	{
		twl_lst_push(output, twl_itoa(twl_jnode_get_prim(node)));
	}
	else if (node->type == JSON_BOOL)
	{
		twl_lst_push(output, twl_jnode_get_prim(node) ? "true" : "false");
	}
	else
	{
		twl_lst_push(output, "?");
	}
}

static void concat_fn(void *token, void *output_str_)
{
	char			**output_str;

	output_str = output_str_;
	*output_str = twl_strjoinfree(*output_str, token, 'l');
}

char				*twl_json_dump(t_jnode *root_node)
{
	t_lst			*out;
	char			*output;

	out = twl_lst_new();
	twl_json_dump_rec(root_node, out);
	output = twl_strdup("");
	twl_lst_iter(out, concat_fn, &output);
	twl_lst_del(out, NULL);
	return output;
}
