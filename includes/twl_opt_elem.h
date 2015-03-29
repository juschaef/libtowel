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

#ifndef TWL_OPT_ELEM_H
# define TWL_OPT_ELEM_H

typedef struct		s_twl_opt_elem
{
	char			*key;
	char			*value;
}					t_opt_elem;

t_opt_elem			*twl_opt_elem_new(char *key, char *value);
void				twl_opt_elem_del(t_opt_elem *twl_opt_elem);

#endif
