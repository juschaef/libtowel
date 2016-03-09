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
#include "twl_stdio.h"
#include "twl_xstdio.h"

static void			push_node_fn(void *node, void *new_node_list)
{
	t_graph_node	*new_node;

	new_node = twl_graph_node_new(twl_graph_node_get_id(node),
											twl_graph_node_get_data(node));
	twl_lst_push_back(new_node_list, new_node);
}

static void			push_edge_fn(void *edge, void *new_graph)
{
	twl_graph_add_edge(new_graph,
		twl_graph_node_get_id(twl_graph_edge_get_left_node(edge)),
		twl_graph_node_get_id(twl_graph_edge_get_right_node(edge)),
		twl_graph_edge_get_data(edge));
}

t_graph				*twl_graph_copy(t_graph *this)
{
	t_graph			*new_graph;

	new_graph = twl_graph_new();
	twl_lst_iter(this->nodes_, push_node_fn, new_graph->nodes_);
	twl_lst_iter(this->edges_, push_edge_fn, new_graph);
	new_graph->node_id_count_ = this->node_id_count_;
	new_graph->edge_id_count_ = this->edge_id_count_;
	return (new_graph);
}
