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

static void			twl_json_dump_rec(t_jnode *node, t_lst *head);

static void			twl_json_dump_one(t_jnode *node, t_jnode *next, t_lst *head)
{
	twl_json_dump_rec(node, head);
	if (next)
	{
		twl_lst_push(head, ",");
	}
}

static void			twl_json_dump_one_void(void *node, void *next, void *head)
{
	twl_json_dump_one(node, next, head);
}

static void			twl_json_dump_rec(t_jnode *node, t_lst *head)
{

	if (node->type == JSON_ARRAY)
	{
		twl_lst_push(head, "[");
		twl_lst_itern(node->value.array, twl_json_dump_one_void, head);
		twl_lst_push(head, "]");
	}
	else if (node->type == JSON_NUMBER)
	{
		twl_lst_push(head, twl_itoa(twl_jnode_get_prim(node)));
	}
	else
	{
		twl_lst_push(head, "?");
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
