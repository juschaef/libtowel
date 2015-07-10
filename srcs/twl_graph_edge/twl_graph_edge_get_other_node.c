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

#include "twl_xstdio.h"

#include "twl_graph_node.h"
#include "twl_graph_edge.h"

t_graph_node		*twl_graph_edge_get_other_node(t_graph_edge *this,
														t_graph_node *src_node)
{
	if (this->left_node_->id_ == src_node->id_)
	{
		return (this->right_node_);
	}
	else if (this->right_node_->id_ == src_node->id_)
	{
		return (this->left_node_);
	}
	twl_xprintf("twl_graph_edge_get_other_node: source node should be either"
													" one of the edge sides.");
	return (NULL);
}
