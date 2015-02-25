/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strjoinarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 12:38:55 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <stdlib.h>
#include <twl_arr.h>
#include <twl_xstring.h>

typedef struct	s_twl_strjoinarr_context
{
	char *output;
	const char *separator;
}				t_twl_strjoinarr_context;

static void *twl_lst_join(void *elem_, void *context_)
{
	t_twl_strjoinarr_context *context;
	t_twl_lst_elem *elem;

	context = context_;
	elem = elem_;
	context->output = twl_strjoinfree(context->output, elem->data, 'l');
	if (elem->next)
		context->output = twl_strjoinfree(context->output, (char *)context->separator, 'l');
	return (context);
}

char		*twl_strjoinarr(const char **arr, const char *sep)
{
	t_lst	*lst;
	t_twl_strjoinarr_context context;

	context.output = twl_strdup("");
	context.separator = sep;

	lst = twl_arr_to_lst(arr);
	twl_lst_reduce(lst, twl_lst_join, &context);

	twl_lst_del(lst, NULL);
	return (context.output);
}
