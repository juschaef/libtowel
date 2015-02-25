/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_sort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 20:27:47 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 22:56:23 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_SORT_H
# define TWL_SORT_H

# include "twl_bool.h"

typedef t_bool	t_troll_norm;
typedef t_bool	(t_sort_cmp_fn)(void *item1, void *item2, void *context);

#endif
