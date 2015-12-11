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
#include "twl_printf.h"
#include "twl_xstdio.h"

char				*twl_lst_strjoin(t_lst *lst, char *sep)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	char			*out;

	out = twl_strdup("");
	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		out = twl_strjoinfree(out, elem->data, 'l');
		if (next)
			out = twl_strjoinfree(out, sep, 'l');
		elem = next;
	}
	return (out);
}
