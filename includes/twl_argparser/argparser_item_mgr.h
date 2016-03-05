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

#ifndef TWL_ARGPARSE_ITEM_MGR_H
# define TWL_ARGPARSE_ITEM_MGR_H

# include <stddef.h>
# include <stdbool.h>
# include "twl_xstring.h"
# include "twl_lst.h"
# include "twl_argparser/argparser_item.h"

t_lst				*argparser_item_mgr_new(void);
void				argparser_item_mgr_del(t_lst *argparser_items);
void				argparser_item_mgr_add(t_lst *argparser_items, t_argparser_item *argparser_item);
void				argparser_item_mgr_remove(t_lst *argparser_items, t_argparser_item *argparser_item);
void				argparser_item_mgr_print(t_lst *argparser_items);

#endif
