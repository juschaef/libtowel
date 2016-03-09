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

t_graph_node_id			twl_graph_add_node(t_graph *graph, void *data)
{
	t_graph_node	*node;

	node = twl_graph_node_new(graph->node_id_count_, data);
	if (!twl_graph_node_mgr_find_by_id(graph->nodes_, node->id_))
	{
		twl_lst_push_back(graph->nodes_, node);
	}
	else
	{
		twl_xprintf("%s duplicate entry", __FILE__);
	}
	graph->node_id_count_++;
	return (node->id_);
}
