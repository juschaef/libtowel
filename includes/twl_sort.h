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

#ifndef TWL_SORT_H
# define TWL_SORT_H

# include <stdbool.h>

typedef bool	t_troll_norm;
typedef bool	(t_sort_cmp_fn)(void *item1, void *item2, void *context);
typedef bool	(t_qsort_cmp_fn)(void *item1, void *item2);

#endif
