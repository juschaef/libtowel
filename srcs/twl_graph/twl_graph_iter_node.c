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

static void			find_node_fn(void *node_, void *iter_fn_, void *context)
{
	t_graph_node	*node;
	void			(*iter_fn)(void *data, void *context);

	node = node_;
	iter_fn = iter_fn_;
	iter_fn(node->data_, context);
}

void				twl_graph_iter_node(t_graph *this,
												void (*iter_fn)(void *data,
												void *context), void *context)
{
	twl_lst_iter2(this->nodes_, find_node_fn, iter_fn, context);
}
