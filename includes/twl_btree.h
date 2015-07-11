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

#ifndef TWL_BTREE_H
# define TWL_BTREE_H

# include "twl_btree_node.h"

typedef struct		s_btree
{
	t_btree_node	*head;
	size_t			size;
}					t_btree;

t_btree				*twl_btree_new();
void				twl_btree_del(t_btree *this);

void				twl_btree_insert(t_btree *this, void *data, int	(*cmp_fn)(void *data, void *cur));

void				*twl_btree_find(t_btree *this, void *data, int (*cmp_fn)(void *data, void *cur));

// void				twl_btree_remove_node(t_btree *this, void *data, int (*cmp_fn)(void *data, void *cur));

size_t				twl_btree_size(t_btree *this);

#endif /* TWL_BTREE_H */
