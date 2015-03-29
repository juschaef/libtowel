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

#ifndef TWL_OPT_H
# define TWL_OPT_H

# include "twl_lst.h"

typedef struct		s_opt
{
	char			*cmd;
	t_lst			*opts;
	char			*valid_opts;
	t_lst			*non_opt_args;
}					t_opt;

t_opt				*twl_opt_new(char **argv, char *valid_opts);
void				twl_opt_del(t_opt *opt);
bool				twl_opt_exist(t_opt *opt, char *opt_key);
char				*twl_opt_check_invalid_opts(t_opt *opt);

char				**twl_opt_new_parse_arg_opt_and_return_non_opt_args__(
								char **arr_opts, t_opt *opt, char *valid_opts);

#endif
