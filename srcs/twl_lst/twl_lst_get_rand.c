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
#include "twl_xstdlib.h"

void	*twl_lst_get_rand(t_lst *lst)
{
	t_lst_elem__	*elem;
	size_t			len;
	int				random;

	len = twl_lst_len(lst);
	random = twl_randint(0, len - 1);
	elem = twl_lst_get_elem__(lst, random);
	if (elem)
		return (elem->data);
	return (NULL);
}
