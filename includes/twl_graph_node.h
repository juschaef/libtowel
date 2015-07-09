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

#ifndef TWL_GRAPH_NODE_H
# define TWL_GRAPH_NODE_H

# include "twl_lst.h"

typedef int			t_node_id;

typedef struct		s_node
{
	t_node_id		id_;
	void			*data_;
	t_lst			*links_;
	bool			is_visited_;
}					t_graph_node;

t_graph_node		*twl_graph_node_new(void *data);
void				twl_graph_node_del(t_graph_node *this,
													void (*del_fn)(void *));

#endif
