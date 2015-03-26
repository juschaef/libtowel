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

#include "twl_stdlib.h"
#include "twl_opt_elem.h"
#include "twl_arr.h"
#include "twl_xstring.h"

void twl_opt_elem_del(t_opt_elem *twl_opt_elem)
{
	twl_free(twl_opt_elem->key);
	twl_free(twl_opt_elem->value);
	twl_free(twl_opt_elem);
}
