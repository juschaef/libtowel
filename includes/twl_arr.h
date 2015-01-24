/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 12:25:26 by yyang             #+#    #+#             */
/*   Updated: 2015/01/21 22:46:13 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_H
# define ARR_H

# include <libft.h>
# include <stddef.h>
# include <twl_bool.h>
# include <lst.h>

size_t	twl_arr_len(void *arr);
void	*twl_arr_rev(void *arr);
void	*twl_arr_cpy(void *arr);
void	twl_arr_del(void *twl_arr_ptr);
void	twl_arr_iter(void *twl_arr_, void (*f)(void *elem, void *context),
															void *context);
void	*twl_arr_last(void *twl_arr_);
void	twl_arr_push(void *twl_arr_, void *elem);
void 	*twl_arr_find(void *twl_arr_, int (*find_fn)(void *arr, void *context), void *context);
void	twl_arr_swap(void *twl_arr_, int i, int j);
void	*twl_arr_init(size_t size);
void	twl_arr_del_elem(void *twl_arr_, int index);
int		twl_arr_indexof(void *twl_arr_, void *target);
void	twl_arr_sort(void *twl_arr_, t_sort_cmp_fn *cmp_fn, void *context);
t_lst 	*twl_arr_to_lst(void *arr);

#endif
