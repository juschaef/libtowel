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

# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

typedef struct		s_node
{
	int				id_;
	void			*data_;
	t_lst			*links_;
	bool			is_visited_;
}					twl_graph_node;

typedef struct		s_graph
{
	t_lst			*nodes_;
}					twl_graph;

twl_graph			*twl_graph_new(void);
void				twl_graph_del(twl_graph *graph,  void (*del_fn)());

void				twl_graph_reset(twl_graph *this);

void				twl_graph_add(twl_graph *this, twl_graph_node *node);
void				twl_graph_link(twl_graph_node *node1, twl_graph_node *node2);
// void				graph_travel(twl_graph *this, int start, void (*fn)(t_node *node));
size_t				twl_graph_size(twl_graph *this);

int					twl_graph_longest_path(twl_graph *this);

twl_graph_node		*twl_graph_node_new(void *data);
void				twl_graph_node_del(twl_graph_node *del, void (*del_fn)(void *));

twl_graph_node		*twl_node_find_by_id(t_lst *nodes, int id);

#endif
