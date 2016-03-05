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

#include "twl_color.h"
#include "twl_argparser/argparser_argument_mgr.h"

static void			print_argparser_argument_fn(void *argparser_argument_)
{
	t_argparser_argument	*argparser_argument;

	argparser_argument = argparser_argument_;
	twl_printf("<Object #%p>\n", argparser_argument);
}

void				argparser_argument_mgr_print(t_lst *arguments)
{
	twl_printf("%s>>>>>>>>>> argparser_argument list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(arguments, print_argparser_argument_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
