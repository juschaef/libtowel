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
#include "twl_graph.h"

static void			iter_edges_fn(void *edge, void *src_node)
{
	t_graph_node	*node;

	node = twl_graph_edge_get_other_node(edge, src_node);
	twl_lprintf("%d,", node->id_);
}

static void			iter_node_fn(void *node_)
{
	t_graph_node	*node;

	node = node_;
	twl_lprintf("Node %d => ", node->id_);
	twl_lst_iter(node->edges_, iter_edges_fn, node);
	twl_lprintf("\n");
}

void				twl_graph_debug_print(t_graph *this)
{
	twl_lst_iter0(this->nodes_, iter_node_fn);
}
