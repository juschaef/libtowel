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

#include "twl_btree_node.h"

t_btree_node		*twl_btree_node_new(void *data)
{
	t_btree_node	*node;

	node = twl_malloc_x0(sizeof(t_btree_node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
