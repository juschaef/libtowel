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

#ifndef TWL_HTAB_H
# define TWL_HTAB_H

# include "twl_lst.h"
# include <stdint.h>
# include "twl_htab_node.h"

# define HTAB_NUMBER_OF_BUCKETS 100

typedef int			(t_htab_compare)(void *a, void *b);
typedef uint32_t	(t_htab_hash)(void *key);

typedef struct		s_htab
{
	t_lst			*buckets[HTAB_NUMBER_OF_BUCKETS];
	t_htab_compare	*compare_fn;
	t_htab_hash		*hash_fn;
	t_copy_key		*copy_key_fn;
}					t_htab;

typedef void		(t_htab_iter_fn)(void *key, void *data, void *context);

t_htab				*twl_htab_new(void);
void				twl_htab_del(t_htab *htab, t_htab_node_del_data_fn *delfn);

int					twl_htab_set(t_htab *htab, void *key, void *data,
												t_htab_node_del_data_fn *delfn);
void				*twl_htab_get(t_htab *htab, void *key);
size_t				twl_htab_len(t_htab *htab);

uint32_t			twl_htab_get_hash_(t_htab *htab, void *key);
t_lst				*twl_htab_get_bucket_(t_htab *htab, uint32_t hash);
t_htab_node			*twl_htab_get_bucket_node_(t_htab *htab, t_lst *bucket,
																	void *key);
t_lst				*twl_htab_get_or_create_bucket_(t_htab *htab,
																uint32_t hash);

void				twl_htab_iter(t_htab *htab, t_htab_iter_fn *iter_fn,
																void *context);

#endif
