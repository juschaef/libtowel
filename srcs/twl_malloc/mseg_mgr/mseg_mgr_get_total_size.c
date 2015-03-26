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
#include "twl_lst.h"

#include "twl_malloc/mseg.h"

static int			sum_mseg_size_fn(void *mseg_, int memo)
{
	t_mseg			*mseg;

	mseg = mseg_;
	return (mseg->size + memo);
}

size_t				mseg_mgr_get_total_size(t_lst *msegs)
{
	return (twl_lst_reducei(msegs, sum_mseg_size_fn, 0));
}
