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

static void			push_neighbor_fn(void *edge, void *neighbors, void *node)
{
	twl_lst_push_back(neighbors,
			twl_graph_edge_get_other_node(edge, node)->data_);
}

t_lst				*twl_graph_node_neighbors_data(t_graph_node *node)
{
	t_lst			*neighbors;

	neighbors = twl_lst_new();
	twl_lst_iter2(node->edges_, push_neighbor_fn, neighbors, node);
	return (neighbors);
}
