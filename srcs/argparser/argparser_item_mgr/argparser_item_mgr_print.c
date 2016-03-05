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
#include "twl_argparser/argparser_item_mgr.h"

static void			print_argparser_item_fn(void *argparser_item_)
{
	t_argparser_item	*argparser_item;

	argparser_item = argparser_item_;
	twl_printf("<Object #%p>\n", argparser_item);
}

void				argparser_item_mgr_print(t_lst *argparser_items)
{
	twl_printf("%s>>>>>>>>>> argparser_item list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(argparser_items, print_argparser_item_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
