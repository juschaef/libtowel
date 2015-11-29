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
#include "twl_xstdio.h"

#define JSON_BOOL_TRUE_LEN 4
#define JSON_BOOL_FALSE_LEN 5

static t_jnode		*twl_json_parse_do(char *json_str, int *len_ptr);

int					twl_json_parse_array(t_jnode *arr_node, char *json_str)
{
	char			*json_str_sav;
	int				len;
	int				total_len;
	t_jnode			*node;

	json_str_sav = json_str;
	json_str++;
	total_len = 2;
	while (*json_str != ']')
	{
		node = twl_json_parse_do(json_str, &len);
		if (!node)
			twl_xprintf("syntax error: %s\n", json_str);
		twl_jnode_array_push(arr_node, node);
		json_str += len;
		total_len += len;
		if (*json_str == ',')
		{
			json_str++;
			total_len++;
		}
	}
	json_str++;
	return (json_str - json_str_sav);
}

static t_jnode		*twl_json_parse_primitive(char *json_str, int *len_ptr)
{
	t_jnode			*node;

	node = NULL;
	if (json_str[0] == 't')
	{
		node = twl_jnode_new_prim(JSON_BOOL, true);
		*len_ptr = JSON_BOOL_TRUE_LEN;
	}
	else if (json_str[0] == 'f')
	{
		node = twl_jnode_new_prim(JSON_BOOL, false);
		*len_ptr = JSON_BOOL_FALSE_LEN;
	}
	return node;
}



static t_jnode		*twl_json_parse_do(char *json_str, int *len_ptr)
{
	t_jnode			*node;


	node = NULL;
	if (*json_str == '[')
	{
		node = twl_jnode_new_array();
		*len_ptr = twl_json_parse_array(node, json_str);;
	}
	else if (twl_strchr(JSON_PRIM_START_CHARS, *json_str))
	{
		node = twl_json_parse_primitive(json_str, len_ptr);
	}
	return node;
}

t_jnode				*twl_json_parse(char *json_str)
{
	int				len;
	t_jnode			*node;

	node = twl_json_parse_do(json_str, &len);
	return node;
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
