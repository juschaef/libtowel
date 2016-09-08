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

static void			iter_neighbors_fn(t_graph_node *node, void *frontier,
													void *closed,
													t_graph_node *cur_node)
{
	if (!twl_graph_node_mgr_contains(closed, node))
	{
		twl_lst_push_back(frontier, node);
		twl_lst_push_back(closed, node);
		node->came_from_ = cur_node;
	}
}

static void			neighbors_iter(t_lst *neighbors, t_lst *frontier,
									t_lst *closed, t_graph_node *cur_node)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;

	elem = neighbors->head;
	while (elem)
	{
		next = elem->next;
		iter_neighbors_fn(elem->data, frontier, closed, cur_node);
		elem = next;
	}
}

static void			handle_neighbors(t_lst *frontier, t_lst *closed,
													t_graph_node *cur_node)
{
	t_lst			*neighbors;

	neighbors = twl_graph_node_neighbors(cur_node);
	neighbors_iter(neighbors, frontier, closed, cur_node);
	twl_lst_del(neighbors, NULL);
}

static t_lst		*get_data_solution_list(t_graph_node *solution_node)
{
	t_lst			*solution;

	solution = twl_lst_new();
	while (solution_node)
	{
		twl_lst_unshift(solution, twl_graph_node_get_data(solution_node));
		solution_node = solution_node->came_from_;
	}
	return (solution);
}

t_lst				*twl_graph_breadth_first_shortest_path(t_graph *this,
												t_graph_node_id start_node_id,
												t_graph_node_id end_node_id)
{
	t_lst			*frontier;
	t_lst			*closed;
	t_graph_node	*temp_node;
	t_graph_node	*cur_node;

	frontier = twl_lst_new();
	closed = twl_lst_new();
	temp_node = twl_graph_get_node(this, start_node_id);
	twl_lst_push_back(frontier, temp_node);
	twl_lst_push_back(closed, temp_node);
	temp_node = twl_graph_get_node(this, end_node_id);
	while (twl_lst_len(frontier) > 0)
	{
		cur_node = twl_lst_shift(frontier);
		if (cur_node == temp_node)
		{
			twl_lst_del(frontier, NULL);
			twl_lst_del(closed, NULL);
			return (get_data_solution_list(cur_node));
		}
		handle_neighbors(frontier, closed, cur_node);
	}
	twl_lst_del(frontier, NULL);
	twl_lst_del(closed, NULL);
	return (NULL);
}
