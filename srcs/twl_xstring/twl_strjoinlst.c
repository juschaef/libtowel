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

static void			twl_lst_join(void *str_, void *next, void *context_)
{
	t_twl_strjoinarr_context	*context;
	char						*str;

	context = context_;
	str = str_;
	context->output = twl_strjoinfree(context->output, str, 'l');
	if (next)
	{
		context->output = twl_strjoinfree(context->output,
											(char *)context->separator, 'l');
	}
}

char				*twl_strjoinlst(t_lst *lst, const char *sep)
{
	t_twl_strjoinarr_context		context;

	context.output = twl_strdup("");
	context.separator = sep;
	twl_lst_itern(lst, twl_lst_join, &context);
	return (context.output);
}
