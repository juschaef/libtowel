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

#ifndef TWL_GRAPH_H
# define TWL_GRAPH_H

# include "twl_lst.h"
# include "twl_graph_node_mgr.h"
# include "twl_graph_edge_mgr.h"

# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

typedef struct		s_graph
{
	t_graph_node_id		node_id_count_;
	t_graph_edge_id	edge_id_count_;
	t_lst			*nodes_;
	t_lst			*edges_;
}					t_graph;

t_graph				*twl_graph_new(void);
void				twl_graph_del(t_graph *graph, void (*del_fn)());

t_graph_node_id			twl_graph_add_node(t_graph *this, void *data);
t_graph_edge_id		twl_graph_add_edge(t_graph *this, t_graph_node_id node_id1,
											t_graph_node_id node_id2, void *data);

void				*twl_graph_get_node_data(t_graph *this, t_graph_node_id node_id);



void				twl_graph_reset(t_graph *this);
int					twl_graph_longest_path(t_graph *this);
size_t				twl_graph_node_count(t_graph *this);

#endif
