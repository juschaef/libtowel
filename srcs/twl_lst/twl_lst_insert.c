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

void	twl_lst_insert(t_lst *lst, int index, void *data)
{
	t_lst_elem__ *elem;

	if (index == 0)
		twl_lst_unshift(lst, data);
	else if (index >= (int)twl_lst_len(lst))
		twl_putstr_fd("\n[warning] Index does not exist !\n", 2);
	else
	{
		elem = twl_lst_get_elem__(lst, index);
		twl_lst_link3__(elem->prev, twl_lst_create_elem__(data), elem);
	}
}
