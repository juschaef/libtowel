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
		t_lst		*seq;
		char		*string;
		int			primitive;
	}				value;
	char			*object_key;
	struct s_jnode *parent;
}					t_jnode;

t_jnode				*twl_jnode_new();
t_jnode				*twl_jnode_new_primitive(t_jnode_type type, int value);
t_jnode				*twl_jnode_new_seq(t_jnode_type type);

void				twl_jnode_del(t_jnode *node);

bool				twl_jnode_is_type(t_jnode *node, t_jnode_type type);

int					twl_jnode_get_primitive(t_jnode *node);
t_lst				*twl_jnode_get_seq(t_jnode *node);

#endif
