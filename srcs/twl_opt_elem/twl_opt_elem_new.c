/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_elem_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 11:17:49 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_opt_elem.h"
#include "twl_arr.h"
#include "twl_xstring.h"

t_opt_elem	*twl_opt_elem_new(char *key, char *value)
{
	t_opt_elem *twl_opt_elem;

	twl_opt_elem = twl_malloc(sizeof(t_opt_elem));
	twl_opt_elem->key = twl_strdup(key);
	if (value)
		twl_opt_elem->value = twl_strdup(value);
	else
		twl_opt_elem->value = NULL;
	return (twl_opt_elem);
}
