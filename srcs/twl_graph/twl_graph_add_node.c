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

t_node_id			twl_graph_add_node(t_graph *graph, void *data)
{
	t_graph_node	*node;

	node = twl_graph_node_new(data);
	if (!twl_graph_node_mgr_find_by_id_(graph->nodes_, node->id_))
	{
		twl_lst_push(graph->nodes_, node);
	}
	else
	{
		twl_xprintf("duplicate entry");
	}
	return (node->id_);
}
