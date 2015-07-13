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

static bool			is_target_edge_fn(void *edge_, void *node_id_ptr)
{
	t_graph_node_id node_id;
	t_graph_edge	*edge;
	bool			return_value;

	node_id = *(t_graph_node_id *)node_id_ptr;
	edge = edge_;
	return_value = edge->left_node_->id_ == node_id
						|| edge->right_node_->id_ == node_id;
	return (return_value);
}

static void			iter_node_fn(void *node, void *node_id_ptr)
{
	twl_lst_remove_if(twl_graph_node_get_edges(node), is_target_edge_fn,
															node_id_ptr, NULL);
}

void				twl_graph_clear_node(t_graph *graph,
													t_graph_node_id node_id)
{
	twl_lst_iter(graph->nodes_, iter_node_fn, &node_id);
	twl_lst_remove_if(graph->edges_, is_target_edge_fn, &node_id, NULL);
}
