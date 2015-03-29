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
#include "twl_opt_elem.h"
#include "twl_arr.h"
#include "twl_xstring.h"

t_opt_elem	*twl_opt_elem_new(char *key, char *value)
{
	t_opt_elem *twl_opt_elem;

	twl_opt_elem = malloc(sizeof(t_opt_elem));
	twl_opt_elem->key = twl_strdup(key);
	if (value)
		twl_opt_elem->value = twl_strdup(value);
	else
		twl_opt_elem->value = NULL;
	return (twl_opt_elem);
}
