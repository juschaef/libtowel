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

#include "twl_graph_node.h"

#include "twl_xstdlib.h"

void				twl_graph_node_del(t_graph_node *node,
														void (*del_fn)(void *))
{
	if (del_fn)
	{
		del_fn(node->data_);
	}
	twl_lst_del(node->edges_, NULL);
	free(node);
}
