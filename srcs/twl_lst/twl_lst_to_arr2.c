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
#include "twl_arr2.h"
#include "twl_lst.h"

#include <stdio.h>

void			*new_fn(int y, int x, void *context_)
{
	t_lst_to_arr2_context__ *context;

	context = context_;
	return (twl_lst_get(context->lst, x + (context->cols * y)));
}

void			*twl_lst_to_arr2(t_lst *lst, int cols)
{
	void					***new_arr;
	size_t					lines;
	t_lst_to_arr2_context__	context;

	context.lst = lst;
	context.cols = cols;
	lines = (twl_lst_len(lst) / cols) + 1;
	new_arr = twl_arr2_new(lines, cols, new_fn, &context);
	return (new_arr);
}
