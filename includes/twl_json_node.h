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

#ifndef TWL_JSON_NODE_H
# define TWL_JSON_NODE_H

# include "twl_lst.h"

typedef enum		e_jsnode_type
{
	JSON_OBJECT,
	JSON_ARRAY,
	JSON_STRING,
	JSON_NULL,
	JSON_BOOL,
	JSON_NUMBER
}					t_jnode_type;

typedef struct		s_json_node
{
	t_jnode_type	type__;
	union
	{
		t_lst		*object__;
		t_lst		*array__;
		int			number__;
		int			boolean__;
	}				value__;
	char			*object_key__;
}					t_json_node;

t_json_node			*twl_json_node_new(void);
void				twl_json_node_del(t_json_node *node);

bool				twl_json_node_is_bool(t_json_node *node);
void				twl_json_node_set_bool(t_json_node *node, bool bool_val);
bool				twl_json_node_get_bool(t_json_node *node);

#endif
