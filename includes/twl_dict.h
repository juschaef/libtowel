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

#ifndef TWL_DICT_H
# define TWL_DICT_H

# include "twl_lst.h"

typedef t_lst			t_dict;
typedef t_lst_elem__	t_dict_elem;

/*
** Basics
*/

t_dict				*twl_dict_new(void);
t_lst				*twl_dict_copy(t_lst *lst, void *(*copy_fn)(void *data));
void				twl_dict_del(t_dict *dict, void (*delfn)(void *));
size_t				twl_dict_len(t_dict *dict);

void				*twl_dict_get(t_dict *dict, char *key);
void				twl_dict_add(t_dict *dict, char *key, void *data);
void				twl_dict_set(t_dict *dict, char *key, void *data,
															void (*delfn)());
void				twl_dict_delone(t_dict *dict, char *key,
															void (*delfn)());
bool				twl_dict_key_exist(t_dict *dict, char *key);

/*
** iter
*/

void				twl_dict_iter(t_lst *lst,
	void (*f)(char *key, void *data, void *context), void *context);
void				twl_dict_itern(t_lst *lst,
	void (*f)(char *key, void *data, void *next, void *context), void *context);
t_lst				*twl_dict_keys(t_dict *dict);

/*
** private
*/

t_dict_elem			*twl_dict_get_elem__(t_dict *dict, char *key);
void				*twl_dict_key_from_value(t_dict *dict,
						bool (*f)(void *data, void *value), void *value);

#endif
