/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strjoinlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/03/07 14:47:46 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_string.h"
#include "twl_arr.h"
#include "twl_xstring.h"

static void *twl_lst_join(void *elem_, void *context_)
{
	t_twl_strjoinarr_context	*context;
	t_lst_elem__				*elem;

	context = context_;
	elem = elem_;
	context->output = twl_strjoinfree(context->output, elem->data, 'l');
	if (elem->next)
		context->output = twl_strjoinfree(context->output,
											(char *)context->separator, 'l');
	return (context);
}

char		*twl_strjoinlst(t_lst *lst, const char *sep)
{
	t_twl_strjoinarr_context context;

	context.output = twl_strdup("");
	context.separator = sep;
	twl_lst_reduce(lst, twl_lst_join, &context);
	return (context.output);
}
