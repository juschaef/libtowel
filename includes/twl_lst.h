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

#ifndef TWL_LST_H
# define TWL_LST_H

# include "twl_string.h"
# include "twl_sort.h"

typedef struct				s_lst_elem__
{
	void					*data;
	struct s_lst_elem__		*next;
	struct s_lst_elem__		*prev;
	char					*key;
}							t_lst_elem__;

typedef struct				s_lst
{
	t_lst_elem__			*head;
}							t_lst;

/*
** Basics
*/

t_lst						*twl_lst_new(void);
t_lst						*twl_lst_new_fill(int nbr,
							void *(*constructor)(void));
void						twl_lst_del(t_lst *lst, void (*delfn)());
t_lst						*twl_lst_copy(t_lst *lst,
							void *(*copy_fn)(void *data));
t_lst						*twl_lst_copy_until(t_lst *lst,
							void *(*copy_fn)(void *data), void *sentinel);
void						*twl_lst_get(t_lst *lst, int index);
void						*twl_lst_get_rand(t_lst *lst);
size_t						twl_lst_len(t_lst *lst);
void						*twl_lst_last(t_lst *lst);
void						*twl_lst_first(t_lst *lst);

/*
** Aggregate
*/

size_t						twl_lst_count(t_lst *lst,
						bool (*f)(void *data, void *context), void *context);

/*
** Search
*/

int							twl_lst_indexof(t_lst *lst, void *target);
void						*twl_lst_find(t_lst *lst,
						bool (*f)(void *data, void *context), void *context);

void						*twl_lst_find2(t_lst *lst,
						bool (*iter_fn)(void *data, void *ctx1, void *ctx2),
						void *ctx1, void *ctx2);
void						*twl_lst_find_and_pop(t_lst *lst,
						bool (*f)(void *data, void *context), void *context);
t_lst						*twl_lst_findall(t_lst *lst,
					bool (*iter_fn)(void *data, void *context), void *context);

/*
** Move
*/
void						*twl_lst_pop_front(t_lst *lst);
void						*twl_lst_pop_back(t_lst *lst);
void						twl_lst_push_front(t_lst *lst, void *data);
void						twl_lst_push_back(t_lst *lst, void *data);
void						twl_lst_insert(t_lst *lst, int index, void *data);
void						twl_lst_insert_lst(t_lst *lst_dest, int index,
															t_lst *lst_src);
void						*twl_lst_popi(t_lst *lst, int index);
void						twl_lst_unshift(t_lst *lst, void *data);
void						*twl_lst_shift(t_lst *lst);
void						twl_lst_swap(t_lst *lst, int i, int j);
void						twl_lst_cat(t_lst *lst_dest, t_lst *lst_src);
t_lst						*twl_lst_slice(t_lst *lst, int begin, int end);

void						twl_lst_remove_mult(t_lst *lst, int begin, int end,
															void (*delfn)());

/*
** Collection
*/

void						twl_lst_iter(t_lst *lst,
						void (*f)(void *data, void *context), void *context);
void						twl_lst_iterb(t_lst *lst, void (*f)(void *data,
												void *context), void *context);
void						twl_lst_itern(t_lst *lst,
		void (*f)(void *data, void *next_data, void *context), void *context);
void						twl_lst_iterp(t_lst *lst,
	void (*f)(void *data, void *next_data, void *context), void *context);
void						twl_lst_iteri(t_lst *lst,
	void (*iter_fn)(void *data, int index, void *context), void *context);
void						twl_lst_iter2(t_lst *lst,
		void (*f)(void *data, void *ctx1, void *ctx2), void *ctx1, void *ctx2);
void						twl_lst_iter2n(t_lst *lst,
		void (*f)(void *data, void *next, void *ctx1, void *ctx2),
		void *ctx1, void *ctx2);
void						twl_lst_iter0(t_lst *lst, void (*f)(void *data));
void						twl_lst_iternp(t_lst *lst, void (*f)(void *data,
	void *prev_data, void *next_data, void *context), void *context);

void						twl_lst_remove_if(t_lst *lst,
	bool (*filter_fn)(void *data, void *context),
	void *context, void (*delfn)(void *));
t_lst						*twl_lst_map(t_lst *lst, void *(*f)(void *data));
void						*twl_lst_reduce(t_lst *lst,
						void *(*fn)(void *data, void *memo), void *context);
int							twl_lst_reducei(t_lst *lst,
								int (*fn)(void *data, int memo), int memo);
void						twl_lst_shuffle(t_lst *lst);
void						twl_lst_extend(t_lst *dst, t_lst *src);
void						twl_lst_extend_front(t_lst *dst, t_lst *src);
/*
** Misc
*/

void						twl_lst_sort(t_lst *lst,
									t_sort_cmp_fn *cmp_fn, void *context);
void						twl_lst_qsort(t_lst *lst, t_qsort_cmp_fn *cmp_fn);
void						twl_lst_rev(t_lst *lst);
void						twl_lst_putstr(t_lst *lst, char *sep);
char						*twl_lst_strjoin(t_lst *lst, char *sep);

/*
** Convert
*/

void						**twl_lst_to_arr(t_lst *lst);
void						*twl_lst_to_arr2(t_lst *lst, int cols);

/*
** Private
*/

t_lst_elem__				*twl_lst_get_elem__(t_lst *lst, int index);
t_lst_elem__				*twl_lst_create_elem__(void *data);
void						twl_lst_del_elem__(t_lst *lst,
									t_lst_elem__ *elem,
														void (*delfn)());
void						twl_lst_iter_elem__(t_lst *lst,
			void (*f)(t_lst_elem__ *elem, void *context), void *context);
void						twl_lst_link__(t_lst_elem__ *elem1,
													t_lst_elem__ *elem2);
void						twl_lst_link3__(t_lst_elem__ *elem1,
									t_lst_elem__ *elem2, t_lst_elem__ *elem3);

void						twl_lst_clear(t_lst *lst, void (*delfn)());

#endif
