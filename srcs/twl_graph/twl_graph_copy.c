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

t_graph				*twl_graph_copy(t_graph *this)
{
	t_graph			*new_graph;

	new_graph = twl_graph_new();
	new_graph->nodes_ = twl_lst_copy(this->nodes_, twl_graph_node_copy_void);
	new_graph->edges_ = twl_lst_copy(this->edges_, twl_graph_node_copy_void);
	new_graph->node_id_count_ = this->node_id_count_;
	new_graph->edge_id_count_ = this->edge_id_count_;
	return (new_graph);
}
