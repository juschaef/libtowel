/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_elem.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:43:29 by emaniez           #+#    #+#             */
/*   Updated: 2015/02/25 11:06:09 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_OPT_ELEM_H
# define TWL_OPT_ELEM_H

typedef struct	s_twl_opt_elem
{
	char		*key;
	char		*value;
}				t_opt_elem;

t_opt_elem	*twl_opt_elem_new(char *key, char *value);
void			twl_opt_elem_del(t_opt_elem *twl_opt_elem);

#endif
