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
# include "twl_dict.h"

typedef enum		e_jnode_type
{
	JSON_OBJECT,
	JSON_ARRAY,
	JSON_STRING,
	JSON_NULL,
	JSON_BOOL,
	JSON_NUMBER
}					t_jnode_type;

typedef struct		s_jnode
{
	t_jnode_type	type;
	union
	{
		t_lst		*array;
		t_dict		*object;
		char		*string;
		int			prim;
	}				value;
	struct s_jnode *parent;
}					t_jnode;

t_jnode				*twl_jnode_new();
t_jnode				*twl_jnode_new_prim(t_jnode_type type, int value);
t_jnode				*twl_jnode_new_array(void);
t_jnode				*twl_jnode_new_object(void);
t_jnode				*twl_jnode_new_null(void);

void				twl_jnode_del(t_jnode *node);

int					twl_jnode_get_prim(t_jnode *node);
// t_lst				*twl_jnode_get_seq(t_jnode *node);

void				twl_jnode_array_push(t_jnode *seq_node, t_jnode *node);
t_jnode				*twl_jnode_array_get(t_jnode *seq_node, int index);

void				twl_jnode_object_add(t_jnode *seq_node,
													t_jnode *node, char *key);
t_jnode				*twl_jnode_object_get(t_jnode *seq_node, char *key);

#endif
