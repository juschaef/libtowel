/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:33:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/23 21:10:01 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# include <stddef.h>
# include <libft.h>

typedef struct			s_lst_elem
{
	void				*data;
	struct s_lst_elem	*next;
	struct s_lst_elem	*prev;
	struct s_lst		*parent;
	char				*key;
}						t_lst_elem;

typedef struct			s_lst
{
	size_t				len;
	t_lst_elem			*elems;
}						t_lst;

void					lst_push(t_lst *lst, void *data);
size_t					lst_len(t_lst *lst);
int						lst_indexof(t_lst *lst, void *target, int (*cmp_fn)());
void					lst_del_elem(t_lst *lst, int index, void (*delfn)());
void					lst_sort(t_lst *lst, t_sort_cmp_fn *cmp_fn, void *context);
void					lst_clear(t_lst *lst, void (*delfn)());
size_t					lst_count(t_lst *lst, void *(*f)(void *));
void					*lst_find_by_value(t_lst *lst, int (*f)(void *data, void *value), void *value);
void					*lst_reduce(t_lst *lst, void *(*fn)(void *data, void *memo), void *context);
void					lst_iter(t_lst *lst, void (*f)(void *data, void *context), void *context);
void					*lst_find(t_lst *lst, void *(*f)(void *));
t_lst					*lst_map(t_lst *lst, void *(*f)(void *data));
void					lst_pop(t_lst *lst, void (*f)());
int 					lst_reducei(t_lst *lst, int (*fn)(void *data, int memo), int memo);
void					lst_unshift(t_lst *lst, void *data);
void					lst_del(t_lst *lst, void (*delfn)());


void					lst_iter_elem_(t_lst *lst, void (*f)(t_lst_elem *elem, void *context), void *context);
void					lst_push_elem_(t_lst *lst, t_lst_elem *newelem);
t_lst					*lst_init(void);
t_lst_elem				*lst_create_elem_(void *data);
t_lst_elem				*lst_get_(t_lst *lst, size_t index);
void					lst__link_(t_lst_elem *elem1, t_lst_elem *elem2);
void 					**lst_to_twl_arr_(t_lst *lst);
void					lstelem_del(t_lst_elem *elem, void (*delfn)());




#endif
