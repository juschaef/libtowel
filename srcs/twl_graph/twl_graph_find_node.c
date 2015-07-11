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

static bool			find_node_fn(void *node_, void *find_fn_, void *context)
{
	t_graph_node	*node;
	bool			(*find_fn)(void *data, void *context);

	node = node_;
	find_fn = find_fn_;
	return (find_fn(node->data_, context));
}

t_graph_node		*twl_graph_find_node(t_graph *this,
												bool (*find_fn)(void *data,
												void *context), void *context)
{
	return (twl_lst_find2(this->nodes_, find_node_fn, find_fn, context));
}
