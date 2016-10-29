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

#ifndef TWL_BTREE_NODE_H
# define TWL_BTREE_NODE_H

#include <stdlib.h>

#include "twl_xstdlib.h"

typedef struct		s_btree_node
{
	void			*data;
	struct s_btree_node	*left;
	struct s_btree_node	*right;
}					t_btree_node;

t_btree_node		*twl_btree_node_new(void *data);
void				twl_btree_node_del(t_btree_node *this, void (*del_fn)(void *));

#endif /* TWL_BTREE_H */
