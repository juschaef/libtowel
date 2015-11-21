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

static bool			is_target_node_fn(void *node_, void *node_id_ptr)
{
	t_graph_node_id node_id;
	t_graph_node	*node;

	node_id = *(t_graph_node_id *)node_id_ptr;
	node = node_;
	return (node->id_ == node_id);
}

void				twl_graph_remove_node(t_graph *graph,
													t_graph_node_id node_id)
{
	twl_lst_remove_if(graph->nodes_, is_target_node_fn, &node_id, NULL);
}
