/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_dict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:20:27 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:43:05 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_DICT_H
# define TWL_DICT_H
# include <twl_lst.h>

typedef t_lst	t_dict;
typedef t_twl_lst_elem	t_twl_dict_elem;

/*
** Basics
*/

void			twl_dict_add(t_dict *dict, char *key, void *data);
void			*twl_dict_get(t_dict *dict, char *key);
void			twl_dict_set(t_dict *dict, char *key, void *data,
															void (*delfn)());
void			twl_dict_delone(t_dict *dict, char *key, void (*delfn)());

/*
** iter
*/

/*
** private
*/
t_twl_dict_elem	*twl_dict_get_elem__(t_dict *dict, char *key);

#endif
