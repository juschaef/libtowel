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

t_graph				*twl_graph_new(void)
{
	t_graph			*graph;

	graph = twl_malloc_x0(sizeof(t_graph));
	graph->nodes_ = twl_lst_new();
	graph->edges_ = twl_lst_new();
	graph->node_id_count_ = 0;
	graph->edge_id_count_ = 0;
	return (graph);
}
