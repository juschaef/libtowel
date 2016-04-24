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

#ifndef TWL_ARGPARSER_ARGUMENT_MGR_H
# define TWL_ARGPARSER_ARGUMENT_MGR_H

# include <stddef.h>
# include <stdbool.h>
# include "twl_xstring.h"
# include "twl_lst.h"
# include "twl_argparser/argparser_argument.h"

t_lst				*argparser_argument_mgr_new(void);
void				argparser_argument_mgr_del(t_lst *arguments);
void				argparser_argument_mgr_add(t_lst *arguments,
									t_argparser_argument *argparser_argument);
void				argparser_argument_mgr_remove(t_lst *arguments,
									t_argparser_argument *argparser_argument);
void				argparser_argument_mgr_print(t_lst *arguments);

char				*argparser_argument_mgr_get_all_chars(t_lst *arguments);

#endif
