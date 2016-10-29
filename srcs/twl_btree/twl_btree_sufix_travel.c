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


static void			process_recursive(t_btree_node *node, void (*tr_fn)(void *data, void *ctx), void *ctx)
{
	if (node->left)
		process_recursive(node->left, tr_fn, ctx);
	if (node->right)
		process_recursive(node->right, tr_fn, ctx);
	tr_fn(node->data, ctx);
}

void				twl_btree_sufix_travel(t_btree *this, void (*tr_fn)(void *data, void *ctx), void *ctx)
{
	process_recursive(this->head, tr_fn, ctx);
}
