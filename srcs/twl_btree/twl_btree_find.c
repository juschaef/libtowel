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

#include "twl_btree.h"

static void			*process_recursiv(t_btree_node *cur_node, t_btree_node *new_node, int (*cmp_fn)(void *data, void *cur_data))
{
	if (cmp_fn(cur_node->data, new_node->data) > 0)
	{
		if (cur_node->left)
			return (process_recursiv(cur_node->left, new_node, cmp_fn));
		else
			return (NULL);
	}
	else if (cmp_fn(cur_node->data, new_node->data) == 0)
	{
		return (cur_node->data);
	}
	else
	{
		if (cur_node->right)
			return (process_recursiv(cur_node->right, new_node, cmp_fn));
		else
			return (NULL);
	}
}

void				*twl_btree_find(t_btree *this, void *data, int (*cmp_fn)(void *data, void *cur_data))
{
	t_btree_node	*new_node;
	t_btree_node	*tmp;

	new_node = twl_btree_node_new(data);
	tmp = this->head;
	if (!tmp)
		return (NULL);
	else
	{
		return (process_recursiv(tmp, new_node, cmp_fn));
	}
}
