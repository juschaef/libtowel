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

#include "twl_graph.h"
#include "twl_xstdlib.h"
#include "twl_xstdio.h"

static bool			find_by_id(void *node_, void *id_ptr_)
{
	t_graph_node	*node;
	t_graph_node_id	*id_ptr;

	node = node_;
	id_ptr = id_ptr_;
	return (node->id_ == *id_ptr);
}

t_graph_node		*twl_graph_node_mgr_find_by_id(t_lst *nodes,
												t_graph_node_id node_id)
{
	return (twl_lst_find(nodes, find_by_id, &node_id));
}
