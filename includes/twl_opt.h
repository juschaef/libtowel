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

typedef struct	s_twl_opt
{
	char		*cmd;
	t_lst		*opts;
	t_lst		*non_opt_args;
}				t_twl_opt;

t_twl_opt		*twl_opt_new(char **argv);
void			twl_opt_del(t_twl_opt *twl_opt);
t_bool			twl_opt_exist(t_twl_opt *twl_opt, char *opt_key);
char			*twl_opt_checkerr(t_twl_opt *twl_opt, char *valid_opts);

#endif
