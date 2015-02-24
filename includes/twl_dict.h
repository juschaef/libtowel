/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:20:27 by yyang             #+#    #+#             */
/*   Updated: 2015/02/24 18:15:53 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_DICT_H
# define TWL_DICT_H
# include <twl_lst.h>

typedef t_lst			t_twl_dict;
typedef t_twl_lst_elem	t_twl_dict_elem;

/*
** Basics
*/

t_twl_dict		*twl_dict_new(void);
void			twl_dict_del(t_twl_dict *dict, void (*delfn)(void *));

void			*twl_dict_get(t_twl_dict *dict, char *key);
void			twl_dict_add(t_twl_dict *dict, char *key, void *data);
void			twl_dict_set(t_twl_dict *dict, char *key, void *data,
															void (*delfn)());
void			twl_dict_delone(t_twl_dict *dict, char *key, void (*delfn)());
t_bool			twl_dict_key_exist(t_twl_dict *dict, char *key);
/*
** iter
*/

/*
** private
*/
t_twl_dict_elem	*twl_dict_get_elem__(t_twl_dict *dict, char *key);

#endif
