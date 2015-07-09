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

#include "twl_stdio.h"
#include "twl_graph.h"

static void			iter_node_fn(void *node_)
{
	t_graph_node	*node;

	node = node_;
	twl_printf("node: %s\n", node->data_);
}

void				twl_graph_debug_print(t_graph *this)
{
	twl_lst_iter0(this->nodes_, iter_node_fn);
}
