/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_range.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:18:18 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/28 19:27:27 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_RANGE_H
# define TWL_RANGE_H

void twl_range_iter(int start, int end, void (*iter_fn)(int i, void *context),
																void *context);


#endif