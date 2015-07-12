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
#include "twl_graph_node.h"
#include "twl_graph_edge.h"

#include "twl_xstdlib.h"

void				twl_graph_edge_del(t_graph_edge *this,
														void (*del_fn)(void *))
{
	twl_graph_node_remove_edge(this->left_node_, this);
	twl_graph_node_remove_edge(this->right_node_, this);
	if (del_fn)
	{
		del_fn(this->data_);
	}
	free(this);
}
