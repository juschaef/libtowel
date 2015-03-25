/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:43:29 by emaniez           #+#    #+#             */
/*   Updated: 2015/02/25 22:54:18 by gbarraul         ###   ########.fr       */
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
void				twl_opt_del(t_opt *twl_opt);
bool				twl_opt_exist(t_opt *twl_opt, char *opt_key);
char				*twl_opt_checkerr(t_opt *twl_opt, char *valid_opts);
char				*twl_opt_get_param(t_opt *twl_opt, char *opt_key);

#endif
