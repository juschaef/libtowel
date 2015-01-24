/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_sort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 20:27:47 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:29:19 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_SORT_H
# define TWL_SORT_H

#include <twl_bool.h>

typedef bool (t_sort_cmp_fn)(void *item1, void *item2, void *context);

#endif