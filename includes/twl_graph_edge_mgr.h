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

#ifndef TWL_GRAPH_EDGE_MGR_H
# define TWL_GRAPH_EDGE_MGR_H

# include "twl_lst.h"
# include "twl_graph_edge.h"

t_graph_edge		*twl_graph_edge_mgr_find_by_id(t_lst *edges,
														t_graph_edge_id id);

#endif
