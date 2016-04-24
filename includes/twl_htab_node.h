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

#ifndef TWL_HTAB_NODE_H
# define TWL_HTAB_NODE_H

# include <stdint.h>

typedef void		*(t_copy_key)(void *key);
typedef void		(t_htab_node_del_data_fn)(void *data);

typedef struct		s_htab_node
{
	void			*key;
	void			*data;
	uint32_t		hash;
}					t_htab_node;

t_htab_node			*twl_htab_node_new(void *key, void *data, uint32_t hash,
												t_copy_key *copy_key_fn);
void				twl_htab_node_del(t_htab_node *htab_node,
												t_htab_node_del_data_fn *delfn);
void				twl_htab_node_set_data(t_htab_node *htab_node, void *data,
												t_htab_node_del_data_fn *delfn);

#endif
