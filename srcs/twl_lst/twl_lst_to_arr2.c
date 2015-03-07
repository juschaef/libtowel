/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst_to_arr2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:35:01 by juschaef          #+#    #+#             */
/*   Updated: 2015/03/07 13:55:49 by yyang            ###   ########.fr       */
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
