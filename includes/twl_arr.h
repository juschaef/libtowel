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

#ifndef TWL_ARR_H
# define TWL_ARR_H

# include <stddef.h>
# include "twl_string.h"
# include <stdbool.h>
# include "twl_lst.h"
# include "twl_sort.h"

/*
** Basics
*/

void				*twl_arr_new(size_t size);
size_t				twl_arr_len(void *arr);
void				twl_arr_del(void *twl_arr, void (*del_fn)(void *elem));
void				*twl_arr_cpy(void *arr);

/*
** Move / Del
*/

void				twl_arr_push(void *twl_arr_, void *elem);
void				twl_arr_swap(void *twl_arr_, int i, int j);
void				twl_arr_delone(void *twl_arr_, int index);

/*
** Search
*/

void				*twl_arr_find(void *twl_arr_,
					bool (*find_fn)(void *arr, void *context), void *context);
int					twl_arr_indexof(void *twl_arr_, void *target);
void				*twl_arr_last(void *twl_arr_);

/*
** Iterators
*/

void				twl_arr_iter(void *twl_arr_,
					void (*f)(void *data, void *context), void *context);

void				*twl_arr_filter(void *arr_, bool (*filter_fn)
				(void *data, void *context), void *context);

size_t				twl_arr_count(void *arr_,
	bool (*filter_fn)(void *elem, void *context), void *context);
void				*twl_arr_filter_del(void *arr_, bool (*filter_fn)
			(void *data, void *context), void *context, void (*delfn)(void *));

/*
** Misc
*/

void				twl_arr_sort(void *twl_arr_, t_sort_cmp_fn *cmp_fn,
																void *context);
void				twl_arr_qsort(void *arr_, t_qsort_cmp_fn *cmp_fn);
void				*twl_arr_rev(void *arr);
t_lst				*twl_arr_to_lst(void *arr);
void				twl_arr_putstr(void *arr, char *sep);

#endif
