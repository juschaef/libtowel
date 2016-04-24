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

void				*twl_htab_get(t_htab *htab, void *key)
{
	t_lst			*bucket;
	uint32_t		hash;
	t_htab_node		*node;

	hash = twl_htab_get_hash_(htab, key);
	bucket = twl_htab_get_bucket_(htab, hash);
	if (bucket)
	{
		node = twl_htab_get_bucket_node_(htab, bucket, key);
		if (node)
			return (node->data);
	}
	return (NULL);
}
