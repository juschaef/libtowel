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
#include "twl_xstdio.h"
#include "twl_stdlib.h"

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

static char			*get_primitive_token(char *json_str)
{
	char			*result;
	size_t			len;
	char			*token;

	result = twl_strchr_any(json_str, JSON_STR_END_OF_PRIMITIVE);
	if (result == NULL)
		return (json_str);
	// twl_printf("result %s\n", result);
	len = result - json_str;
	token = twl_strnew(len);
	twl_strncpy(token, json_str, len);
	return (token);
}

static t_jnode		*twl_json_parse_primitive(char *json_str, int *len_ptr)
{
	t_jnode			*node;
	char			*token;

	node = NULL;
	token = get_primitive_token(json_str);
	// twl_printf("===============\n");
	// twl_printf("json_str %s\n", json_str);
	// twl_printf("token %s\n", token);
	if (twl_strequ(token, JSON_STR_TRUE))
	{
		node = twl_jnode_new_prim(JSON_BOOL, true);
		*len_ptr = JSON_STR_TRUE_LEN;
	}
	else if (twl_strequ(token, JSON_STR_FALSE))
	{
		node = twl_jnode_new_prim(JSON_BOOL, false);
		*len_ptr = JSON_STR_FALSE_LEN;
	}
	else if (twl_strequ(token, JSON_STR_NULL))
	{
		node = twl_jnode_new_null();
		*len_ptr = JSON_STR_NULL_LEN;
	}
	else if (twl_str_contains_only(token, JSON_NUMBER_CHARS))
	{
		node = twl_jnode_new_prim(JSON_NUMBER, twl_atoi(token));
		*len_ptr = twl_strlen(token);
	}
	free(token);
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
