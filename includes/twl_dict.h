/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:20:27 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 22:52:19 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_DICT_H
# define TWL_DICT_H

# include "twl_lst.h"

typedef t_lst			t_dict;
typedef t_twl_lst_elem	t_dict_elem;

/*
** Basics
*/

t_dict		*twl_dict_new(void);
void			twl_dict_del(t_dict *dict, void (*delfn)(void *));

void			*twl_dict_get(t_dict *dict, char *key);
void			twl_dict_add(t_dict *dict, char *key, void *data);
void			twl_dict_set(t_dict *dict, char *key, void *data,
															void (*delfn)());
void			twl_dict_delone(t_dict *dict, char *key, void (*delfn)());
bool			twl_dict_key_exist(t_dict *dict, char *key);
/*
** iter
*/

/*
** private
*/
t_dict_elem	*twl_dict_get_elem__(t_dict *dict, char *key);

#endif
