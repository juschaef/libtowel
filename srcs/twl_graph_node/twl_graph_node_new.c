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

#include "twl_graph_node.h"

#include "twl_xstdlib.h"

t_graph_node			*twl_graph_node_new(t_graph_node_id node_id, void *data)
{
	t_graph_node	*node;

	node = twl_malloc_x0(sizeof(t_graph_node));
	node->id_ = node_id;
	node->data_ = data;
	node->edges_ = twl_lst_new();
	node->is_visited_ = 0;
	node->came_from_ = NULL;
	return (node);
}
