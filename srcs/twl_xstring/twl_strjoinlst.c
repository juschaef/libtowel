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
