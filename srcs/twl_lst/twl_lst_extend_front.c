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

#include "twl_lst.h"

void				twl_lst_extend_front(t_lst *dst, t_lst *src)
{
	t_lst			*copy;
	void			*data;

	copy = twl_lst_copy(src, NULL);
	while ((data = twl_lst_pop_back(copy)))
	{
		twl_lst_push_front(dst, data);
	}
	twl_lst_del(copy, NULL);
}
