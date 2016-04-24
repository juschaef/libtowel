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

t_lst				*twl_htab_get_or_create_bucket_(t_htab *htab, uint32_t hash)
{
	t_lst			*bucket;

	bucket = twl_htab_get_bucket_(htab, hash);
	if (!bucket)
	{
		bucket = twl_lst_new();
		htab->buckets[hash] = bucket;
	}
	return (bucket);
}
