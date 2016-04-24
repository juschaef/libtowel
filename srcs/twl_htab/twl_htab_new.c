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
#include "twl_htab.h"

static int			default_compare(void *a, void *b)
{
	return (twl_strcmp(a, b));
}

static uint32_t		default_hash(void *a)
{
	size_t			len;
	char			*key;
	uint32_t		hash;
	uint32_t		i;

	len = twl_strlen(a);
	key = a;
	hash = 0;
	i = 0;
	while (i < len)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i += 1;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

static void			*default_copy_key(void *key)
{
	return (twl_strdup(key));
}

t_htab				*twl_htab_new(void)
{
	t_htab	*htab;

	htab = twl_malloc_x0(sizeof(t_htab));
	htab->compare_fn = default_compare;
	htab->hash_fn = default_hash;
	htab->copy_key_fn = default_copy_key;
	return (htab);
}
