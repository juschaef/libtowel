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

#include "twl_htab.h"

static void			iter_node_fn(void *node_, void *iter_fn_, void *ctx)
{
	t_htab_node		*node;
	t_htab_iter_fn	*iter_fn;

	iter_fn = iter_fn_;
	node = node_;
	iter_fn(node->key, node->data, ctx);
}

void				twl_htab_iter(t_htab *htab, t_htab_iter_fn *iter_fn,
															void *context)
{
	int				i;

	i = 0;
	while (i < HTAB_NUMBER_OF_BUCKETS)
	{
		if (htab->buckets[i])
		{
			twl_lst_iter2(htab->buckets[i], iter_node_fn, iter_fn, context);
		}
		i++;
	}
}
