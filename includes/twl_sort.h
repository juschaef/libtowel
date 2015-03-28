/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_sort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 20:27:47 by yyang             #+#    #+#             */
/*   Updated: 2015/02/28 18:28:31 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_SORT_H
# define TWL_SORT_H

# include <stdbool.h>

typedef bool	t_troll_norm;
typedef bool	(t_sort_cmp_fn)(void *item1, void *item2, void *context);
typedef bool	(t_qsort_cmp_fn)(void *item1, void *item2);

#endif
