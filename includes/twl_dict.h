/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:20:27 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 17:56:03 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LDICT_H
# define LDICT_H
# include <twl_lst.h>

typedef t_lst t_dict;
typedef t_twl_lst_elem t_twl_dict_elem;

/*
** Basics
*/

void			twl_dict_add(t_dict *dict, char *key, void *data);
void			twl_dict_del_by_key(t_dict *dict, char *key, void (*delfn)());
void			*twl_dict_get(t_dict *dict, char *key);
t_twl_dict_elem	*twl_dict_get_elem__(t_dict *dict, char *key);
void			twl_dict_set(t_dict *dict, char *key, void *data, void (*delfn)());

#endif
