/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:43:29 by emaniez           #+#    #+#             */
/*   Updated: 2015/02/24 17:50:24 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_OPT_H
# define TWL_OPT_H

# include <twl_dict.h>

typedef struct	s_twl_opt
{
	char		*cmd;
	t_twl_dict	*opts;
}				t_twl_opt;

t_twl_opt		*twl_opt_new(char **argv);

#endif
