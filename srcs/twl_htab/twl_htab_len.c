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

size_t				twl_htab_len(t_htab *htab)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	while (i < HTAB_NUMBER_OF_BUCKETS)
	{
		if (htab->buckets[i])
		{
			count += twl_lst_len(htab->buckets[i]);
		}
		i++;
	}
	return (count);
}
