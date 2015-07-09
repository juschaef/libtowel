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

#include <stdio.h>

static void			process_recursive(t_graph_node *node, int cur, int *max)
{
	t_lst_elem__	*tmp;
	t_graph_node	*node_tmp;


	tmp = node->links_->head;
	node->is_visited_ = true;
	cur++;
	if (cur > *max)
		*max = cur;
	while (tmp != NULL)
	{
		node_tmp = tmp->data;
		if (node_tmp->is_visited_ == false)
		{
			process_recursive(tmp->data, cur, max);
			node->is_visited_ = false;
		}
		tmp = tmp->next;
	}
}

int					twl_graph_longest_path(t_graph *this)
{
	int				longest_path;
	t_lst_elem__	*tmp;

	longest_path = 0;
	tmp = this->nodes_->head;
	while (tmp != NULL)
	{
		process_recursive(tmp->data, 0, &longest_path);
		twl_graph_reset(this);
		tmp = tmp->next;
	}
	return (longest_path);
}
