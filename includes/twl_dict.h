/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:20:27 by yyang             #+#    #+#             */
/*   Updated: 2015/03/11 16:53:36 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_DICT_H
# define TWL_DICT_H

# include "twl_lst.h"

typedef t_lst			t_dict;
typedef t_lst_elem__	t_dict_elem;

/*
** Basics
*/

t_dict					*twl_dict_new(void);
void					twl_dict_del(t_dict *dict, void (*delfn)(void *));
size_t					twl_dict_len(t_dict *dict);

void					*twl_dict_get(t_dict *dict, char *key);
void					twl_dict_add(t_dict *dict, char *key, void *data);
void					twl_dict_set(t_dict *dict, char *key, void *data,
															void (*delfn)());
void					twl_dict_delone(t_dict *dict, char *key,
															void (*delfn)());
bool					twl_dict_key_exist(t_dict *dict, char *key);

/*
** iter
*/

void					twl_dict_iter(t_lst *lst,
	void (*f)(char *key, void *data, void *context), void *context);

/*
** private
*/

t_dict_elem				*twl_dict_get_elem__(t_dict *dict, char *key);

#endif
