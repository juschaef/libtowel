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

#include "twl_stdio.h"
#include "twl_graph_node.h"

static bool			remove_edge_by_id_fn(void *edge_, void *target_edge_)
{
	return (twl_graph_edge_equal(edge_, target_edge_));
}

void				twl_graph_node_remove_edge(t_graph_node *node,
															t_graph_edge *edge)
{
	twl_lst_remove_if(node->edges_, remove_edge_by_id_fn, edge, NULL);
}
