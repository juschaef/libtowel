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

t_graph_edge_id			twl_graph_add_edge(t_graph *this,
											t_graph_node_id node_id1,
											t_graph_node_id node_id2,
											void *data)
{
	t_graph_node	*node1;
	t_graph_node	*node2;
	t_graph_edge	*edge;

	if (node_id1 == node_id2)
		return (-1);
	node1 = twl_graph_node_mgr_find_by_id(this->nodes_, node_id1);
	node2 = twl_graph_node_mgr_find_by_id(this->nodes_, node_id2);
	edge = twl_graph_edge_new(this->edge_id_count_, node1, node2, data);
	if (!twl_graph_edge_mgr_find_by_id(this->edges_, edge->id_))
	{
		twl_lst_push_back(this->edges_, edge);
	}
	else
	{
		twl_xprintf("%s duplicate entry", __FILE__);
	}
	this->edge_id_count_++;
	return (edge->id_);
}
