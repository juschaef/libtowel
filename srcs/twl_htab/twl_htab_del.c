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

void				twl_htab_del(t_htab *htab, t_htab_node_del_data_fn *delfn)
{
	int				i;

	i = 0;
	while (i < HTAB_NUMBER_OF_BUCKETS)
	{
		if (htab->buckets[i])
		{
			twl_lst_del(htab->buckets[i], delfn);
		}
		i++;
	}
	free(htab);
}
