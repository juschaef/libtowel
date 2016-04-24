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

static bool			find_node_fn(void *node_, void *key, void *htab_)
{
	t_htab_node		*node;
	t_htab			*htab;

	node = node_;
	htab = htab_;
	return (htab->compare_fn(node->key, key) == 0);
}

t_htab_node			*twl_htab_get_bucket_node_(t_htab *htab, t_lst *bucket,
																	void *key)
{
	if (bucket)
	{
		return (twl_lst_find2(bucket, find_node_fn, key, htab));
	}
	return (NULL);
}
