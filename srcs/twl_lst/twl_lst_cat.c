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
#include <assert.h>
#include "twl_lst.h"
#include "twl_xstdio.h"

void	twl_lst_cat(t_lst *lst_dest, t_lst *lst_src)
{
	t_lst_elem__ *elem;

	elem = twl_lst_get_elem__(lst_dest, -1);
	if (!elem)
		lst_dest->head = lst_src->head;
	else
		twl_lst_link__(elem, lst_src->head);
}
