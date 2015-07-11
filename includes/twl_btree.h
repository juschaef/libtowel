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

#include "twl_btree_node.h"

typedef struct		s_btree
{
	t_btree_node	*head;
}					t_btree;

t_btree				*twl_btree_new();
void				twl_btree_del(t_btree *this);

void				twl_btree_insert(t_btree *this, void *data, int	(*cmp_fn)(void *data, void *cur));

#endif /* TWL_BTREE_H */
