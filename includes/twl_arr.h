/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 12:25:26 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 22:06:57 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_ARR_H
# define TWL_ARR_H

# include <twl_string.h>
# include <stddef.h>
# include <twl_bool.h>
# include <twl_lst.h>
# include <twl_sort.h>

/*
** Basics
*/

void	*twl_arr_new(size_t size);
size_t	twl_arr_len(void *arr);
void	twl_arr_del(void *twl_arr_ptr);
void	*twl_matrix_new(int *a);


/*
** Move / Del
*/

void	twl_arr_push(void *twl_arr_, void *elem);
void	twl_arr_swap(void *twl_arr_, int i, int j);
void	twl_arr_delone(void *twl_arr_, int index);

/*
** Search
*/

void	*twl_arr_find(void *twl_arr_, int (*find_fn)(void *arr, void *context),
																void *context);
int		twl_arr_indexof(void *twl_arr_, void *target);
void	*twl_arr_last(void *twl_arr_);

/*
** Iterators
*/

void	twl_arr_iter(void *twl_arr_, void (*f)(void *elem, void *context),
															void *context);

/*
** Misc
*/

void	twl_arr_sort(void *twl_arr_, t_sort_cmp_fn *cmp_fn, void *context);
void	*twl_arr_rev(void *arr);
t_lst	*twl_arr_to_lst(void *arr);

#endif
