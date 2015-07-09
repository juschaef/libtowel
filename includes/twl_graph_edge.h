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

#ifndef TWL_GRAPH_EDGE_H
# define TWL_GRAPH_EDGE_H

# include "twl_graph_node.h"

typedef int			t_graph_edge_id;

typedef struct		s_graph_edge
{
	t_graph_edge_id	id_;
	void			*data_;
	t_graph_node	*left_node_;
	t_graph_node	*right_node_;
	double			weight_;
}					t_graph_edge;

t_graph_edge		*twl_graph_edge_new(t_graph_edge_id edge_id,
						t_graph_node *left_node, t_graph_node *right_node,
						void *data);
void				twl_graph_edge_del(t_graph_edge *this,
													void (*del_fn)(void *));

#endif
