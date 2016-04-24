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

#include "twl_xstdlib.h"
#include "twl_htab_node.h"

t_htab_node		*twl_htab_node_new(void *key, void *data, uint32_t hash,
														t_copy_key *copy_key_fn)
{
	t_htab_node	*htab_node;

	htab_node = twl_malloc_x0(sizeof(t_htab_node));
	htab_node->key = copy_key_fn(key);
	htab_node->data = data;
	htab_node->hash = hash;
	return (htab_node);
}
