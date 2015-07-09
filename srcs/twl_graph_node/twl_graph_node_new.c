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

t_graph_node			*twl_graph_node_new(void *data)
{
	t_graph_node		*node;
	static int		node_id = 0;

	node = twl_malloc_x0(sizeof(t_graph_node));
	node->id_ = node_id;
	node->data_ = data;
	node->links_ = twl_lst_new();
	node->is_visited_ = 0;
	node_id++;
	return (node);
}
