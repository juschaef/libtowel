/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldict.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 13:20:27 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 17:45:42 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LDICT_H
# define LDICT_H
# include <lst.h>

t_lst_elem		*ldict_set(t_lst *lst, char *key, void *data, void (*delfn)());
void			ldict_add(t_lst *lst, char *key, void *data);
void			*ldict_get(t_lst *lst, char *key);
void			ldict_del_elem(t_lst *lst, char *key, void (*delfn)());

#endif
