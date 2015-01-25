/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:33:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/25 14:35:04 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# include <stddef.h>
# include <twl_string.h>
# include <twl_sort.h>

typedef struct				s_twl_lst_elem
{
	void					*data;
	struct s_twl_lst_elem	*next;
	struct s_twl_lst_elem	*prev;
	char					*key;
}							t_twl_lst_elem;

typedef struct			s_lst
{
	t_twl_lst_elem		*head;
}						t_lst;

void					*twl_lst_get(t_lst *lst, size_t index);
void					twl_lst_clear(t_lst *lst, void (*delfn)());
size_t					twl_lst_count(t_lst *lst, void *(*f)(void *));
void					twl_lst_del(t_lst *lst, void (*delfn)());
void					*twl_lst_find(t_lst *lst, void *(*f)(void *));
void					*twl_lst_find_by_value(t_lst *lst, int (*f)(void *data, void *value), void *value);
int						twl_lst_indexof(t_lst *lst, void *target, int (*cmp_fn)());
t_lst					*twl_lst_new(void);
void					twl_lst_iter(t_lst *lst, void (*f)(void *data, void *context), void *context);
size_t					twl_lst_len(t_lst *lst);
t_lst					*twl_lst_map(t_lst *lst, void *(*f)(void *data));
void					twl_lst_pop(t_lst *lst, void (*f)());
void					twl_lst_push(t_lst *lst, void *data);
void					*twl_lst_reduce(t_lst *lst, void *(*fn)(void *data, void *memo), void *context);
int 					twl_lst_reducei(t_lst *lst, int (*fn)(void *data, int memo), int memo);
void					twl_lst_sort(t_lst *lst, t_sort_cmp_fn *cmp_fn, void *context);
void					twl_lst_unshift(t_lst *lst, void *data);
void					twl_lstelem_del(t_twl_lst_elem *elem, void (*delfn)());

t_twl_lst_elem			*twl_lst_get_elem__(t_lst *lst, size_t index);
t_twl_lst_elem			*twl_lst_create_elem__(void *data);
void					twl_lst_del_elem__(t_lst *lst, int index, void (*delfn)());
void					twl_lst_iter_elem__(t_lst *lst, void (*f)(t_twl_lst_elem *elem, void *context), void *context);
void					twl_lst_link__(t_twl_lst_elem *elem1, t_twl_lst_elem *elem2);
void 					**twl_lst_to_arr__(t_lst *lst);

#endif
