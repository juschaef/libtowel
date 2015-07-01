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

static bool			find_by_id(void *node_, void *id_ptr_)
{
	twl_graph_node		*node;
	int				*id_ptr;

	node = node_;
	id_ptr = id_ptr_;
	return (node->id_ == *id_ptr);
}

twl_graph_node		*twl_node_find_by_id(t_lst *nodes, int id)
{
	return (twl_lst_find(nodes, find_by_id, &id));
}
