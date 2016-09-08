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

#include <stdlib.h>
#include "twl_htab.h"
#include "twl_stdio.h"

/*
** Could use twl_htab_node_del instead.
*/

static void			iter_fn(void *data, void *ctx)
{
	t_htab_node				*node;
	t_htab_node_del_data_fn *delfn;

	node = data;
	delfn = ctx;
	delfn(node->data);
}

static void			inner_del_fn(void *data)
{
	t_htab_node		*node;

	node = data;
	free(node->key);
	free(node);
}

void				twl_htab_del(t_htab *htab, t_htab_node_del_data_fn *delfn)
{
	int				i;

	if (!htab)
		return ;
	i = 0;
	while (i < HTAB_NUMBER_OF_BUCKETS)
	{
		if (htab->buckets[i])
		{
			if (delfn)
			{
				twl_lst_iter(htab->buckets[i], iter_fn, delfn);
			}
			twl_lst_del(htab->buckets[i], inner_del_fn);
		}
		i++;
	}
	free(htab);
}
