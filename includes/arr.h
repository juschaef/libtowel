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
# include <ft_bool.h>
# include <lst.h>

size_t	arr_len(void *arr);
void	*arr_rev(void *arr);
void	*arr_cpy(void *arr);
void	arr_del(void *arr_ptr);
void	arr_iter(void *arr_, void (*f)(void *elem, void *context),
															void *context);
void	*arr_last(void *arr_);
void	arr_push(void *arr_, void *elem);
void 	*arr_find(void *arr_, int (*find_fn)(void *arr, void *context), void *context);
void	arr_swap(void *arr_, int i, int j);
void	*arr_init(size_t size);
void	arr_del_elem(void *arr_, int index);
int		arr_indexof(void *arr_, void *target);
void	arr_sort(void *arr_, t_sort_cmp_fn *cmp_fn, void *context);
t_lst 	*arr_to_lst(void *arr);

#endif
