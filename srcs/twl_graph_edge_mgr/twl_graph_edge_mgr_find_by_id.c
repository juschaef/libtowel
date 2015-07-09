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

#include "twl_graph_edge_mgr.h"

static bool			find_by_id(void *edge_, void *id_ptr_)
{
	t_graph_edge	*edge;
	t_graph_edge_id	*id_ptr;

	edge = edge_;
	id_ptr = id_ptr_;
	return (edge->id_ == *id_ptr);
}

t_graph_edge		*twl_graph_edge_mgr_find_by_id(t_lst *edges,
													t_graph_edge_id edge_id)
{
	return (twl_lst_find(edges, find_by_id, &edge_id));
}
