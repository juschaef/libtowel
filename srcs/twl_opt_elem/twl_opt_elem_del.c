/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_elem_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 11:05:46 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_opt_elem.h"
#include "twl_arr.h"
#include "twl_xstring.h"

void twl_opt_elem_del(t_opt_elem *twl_opt_elem)
{
	free(twl_opt_elem->key);
	free(twl_opt_elem->value);
	free(twl_opt_elem);
}
