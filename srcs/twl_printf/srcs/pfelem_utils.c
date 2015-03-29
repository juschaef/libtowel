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

#include "twl_printf.h"

int	pfelem_fill_before_padding(t_pfelem *pfelem)
{
	int is_zero;
	int is_plus_or_space;

	is_zero = (pfelem->flags & FLAG_ZERO_MASK);
	is_plus_or_space = (pfelem->flags & FLAG_PLUS_MASK
						|| pfelem->flags & FLAG_SPACE_MASK);
	return (is_zero && is_plus_or_space);
}
