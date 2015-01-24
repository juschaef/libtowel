/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:21:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/14 13:51:29 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	pfelem_fill_before_padding(t_pfelem *pfelem)
{
	int is_zero;
	int is_plus_or_space;

	is_zero = (pfelem->flags & FLAG_ZERO_MASK);
	is_plus_or_space = (pfelem->flags & FLAG_PLUS_MASK
						|| pfelem->flags & FLAG_SPACE_MASK);
	return (is_zero && is_plus_or_space);
}
