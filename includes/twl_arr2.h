/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_arr2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:31:03 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 20:45:45 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_MAP_H
# define TWL_MAP_H

void	twl_arr2_iter(void *map_, void (*iter_fn)(void *data, void *context),
																void *context);
void	*twl_arr2_new(int rows, int cols,
		void *(*new_fn)(int y, int x, void *context), void *context);
void	*twl_arr2_rotate(void *arr_, int times);

#endif