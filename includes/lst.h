/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:33:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 15:29:42 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# include <stddef.h>
# include <libft.h>

typedef struct				s_twl_lst_elem
{
	void					*data;
	struct s_twl_lst_elem	*next;
	struct s_twl_lst_elem	*prev;
	struct s_lst			*parent;
	char					*key;
}							t_twl_lst_elem;

typedef struct			s_lst
{
	size_t				len;
	t_twl_lst_elem		*elems;
}						t_lst;

void					twl_lst_push(t_lst *lst, void *data);
size_t					twl_lst_len(t_lst *lst);
int						twl_lst_indexof(t_lst *lst, void *target, int (*cmp_fn)());
void					twl_lst_del_elem(t_lst *lst, int index, void (*delfn)());
void					twl_lst_sort(t_lst *lst, t_sort_cmp_fn *cmp_fn, void *context);
void					twl_lst_clear(t_lst *lst, void (*delfn)());
size_t					twl_lst_count(t_lst *lst, void *(*f)(void *));
void					*twl_lst_find_by_value(t_lst *lst, int (*f)(void *data, void *value), void *value);
void					*twl_lst_reduce(t_lst *lst, void *(*fn)(void *data, void *memo), void *context);
void					twl_lst_iter(t_lst *lst, void (*f)(void *data, void *context), void *context);
void					*twl_lst_find(t_lst *lst, void *(*f)(void *));
t_lst					*twl_lst_map(t_lst *lst, void *(*f)(void *data));
void					twl_lst_pop(t_lst *lst, void (*f)());
int 					twl_lst_reducei(t_lst *lst, int (*fn)(void *data, int memo), int memo);
void					twl_lst_unshift(t_lst *lst, void *data);
void					twl_lst_del(t_lst *lst, void (*delfn)());


void					twl_lst_iter_elem_(t_lst *lst, void (*f)(t_twl_lst_elem *elem, void *context), void *context);
void					twl_lst_push_elem_(t_lst *lst, t_twl_lst_elem *newelem);
t_lst					*twl_lst_init(void);
t_twl_lst_elem			*twl_lst_create_elem_(void *data);
t_twl_lst_elem			*twl_lst_get_(t_lst *lst, size_t index);
void					twl_lst__link_(t_twl_lst_elem *elem1, t_twl_lst_elem *elem2);
void 					**twl_lst_to_arr_(t_lst *lst);
void					lstelem_del(t_twl_lst_elem *elem, void (*delfn)());

#endif
