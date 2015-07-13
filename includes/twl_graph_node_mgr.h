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

#ifndef TWL_GRAPH_NODE_MGR_H
# define TWL_GRAPH_NODE_MGR_H

# include "twl_lst.h"
# include "twl_graph_node.h"

t_graph_node		*twl_graph_node_mgr_find_by_id(t_lst *nodes,
														t_graph_node_id id);
bool				twl_graph_node_mgr_contains(t_lst *nodes,
														t_graph_node *node);

#endif
