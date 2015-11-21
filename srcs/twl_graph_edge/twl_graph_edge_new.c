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

#include "twl_xstdio.h"

#include "twl_graph_node.h"
#include "twl_graph_edge.h"

#include "twl_xstdlib.h"

t_graph_edge		*twl_graph_edge_new(t_graph_edge_id edge_id,
						t_graph_node *left_node, t_graph_node *right_node,
						void *data)
{
	t_graph_edge	*edge;

	if (!left_node || !right_node)
	{
		twl_xprintf("twl_graph_edge_new: left and right nodes are required");
	}
	edge = twl_malloc_x0(sizeof(t_graph_edge));
	edge->id_ = edge_id;
	edge->data_ = data;
	edge->left_node_ = left_node;
	edge->right_node_ = right_node;
	edge->weight_ = GRAPH_EDGE_DEFAULT_WEIGHT;
	twl_graph_node_add_edge(left_node, edge);
	twl_graph_node_add_edge(right_node, edge);
	return (edge);
}
