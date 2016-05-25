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

#include <stdlib.h>

#include "twl_stdio.h"

#include "twl_graph.h"

#include "twl_xstdlib.h"

static void			del_node_fn(void *node, void *del_node_data_fn)
{
	twl_graph_node_del(node, del_node_data_fn);
}

static void			del_edge_fn(void *edge, void *del_edge_data_fn)
{
	twl_graph_edge_del(edge, del_edge_data_fn);
}

void				twl_graph_del(t_graph *graph,
										void (*del_node_data_fn)(void *),
										void (*del_edge_data_fn)(void *))
{
	twl_lst_iter(graph->edges_, del_edge_fn, del_edge_data_fn);
	twl_lst_iter(graph->nodes_, del_node_fn, del_node_data_fn);
	twl_lst_del(graph->nodes_, NULL);
	twl_lst_del(graph->edges_, NULL);
	free(graph);
}
