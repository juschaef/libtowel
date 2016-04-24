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

int					twl_htab_set(t_htab *htab, void *key, void *data,
												t_htab_node_del_data_fn *delfn)
{
	t_lst			*bucket;
	uint32_t		hash;
	t_htab_node		*node;

	hash = twl_htab_get_hash_(htab, key);
	bucket = twl_htab_get_or_create_bucket_(htab, hash);
	if (!bucket)
		return (-1);
	node = twl_htab_get_bucket_node_(htab, bucket, key);
	if (node)
	{
		twl_htab_node_set_data(node, data, delfn);
	}
	else
	{
		twl_lst_push_back(bucket, twl_htab_node_new(key, data, hash,
															htab->copy_key_fn));
	}
	return (0);
}
