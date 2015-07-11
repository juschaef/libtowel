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

#include "twl_xstdlib.h"
#include "twl_xstdio.h"
#include "twl_stdio.h"

#include "twl_graph.h"
#include "twl_graph_node.h"

static void			iter_neighbors_fn(void *node)
{
	twl_printf("node: %s\n", twl_graph_node_get_data(node));
}

t_lst				*twl_graph_breadth_first_shortest_path(t_graph *this,
												t_graph_node_id start_node_id,
												t_graph_node_id end_node_id)
{
	t_lst			*frontier;
	t_lst			*came_from;
	t_graph_node	*start_node;
	t_graph_node	*end_node;
	t_graph_node	*cur_node;
	t_lst			*neighbors;

	frontier = twl_lst_new();
	came_from = twl_lst_new();
	start_node = twl_graph_get_node(this, start_node_id);
	end_node = twl_graph_get_node(this, end_node_id);
	twl_printf("start_node: %s\n", twl_graph_node_get_data(start_node));
	twl_printf("end_node: %s\n", twl_graph_node_get_data(end_node));
	twl_printf("==================\n");
	twl_lst_push(frontier, start_node);
	twl_lst_push(came_from, start_node);
	while (twl_lst_len(frontier) > 0)
	{
		cur_node = twl_lst_shift(frontier);
		twl_printf("--------- %s ---------\n", twl_graph_node_get_data(cur_node));
		twl_printf("cur_node: %s\n", twl_graph_node_get_data(cur_node));
		if (cur_node == end_node)
			break ;
		neighbors = twl_graph_node_neighbors(cur_node);
		twl_lst_iter0(neighbors, iter_neighbors_fn);
		twl_lst_del(neighbors, NULL);
		twl_printf("len: %zu\n", twl_lst_len(frontier));
	}
	return (NULL);
	(void)this;
}

/*
frontier = Queue()
frontier.put(start)
came_from = {}
came_from[start] = None

while not frontier.empty():
   current = frontier.get()

   if current == goal:
      break

   for next in graph.neighbors(current):
      if next not in came_from:
         frontier.put(next)
         came_from[next] = current

*/
