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

void	pfelem_min_width_pad(t_pfelem *pfelem, int pad_dir, char fill_char)
{
	char	*tmp;
	int		is_neg;
	int		pad_width;

	tmp = pfelem->str;
	is_neg = 0;
	pad_width = pfelem->min_width;
	if ((*(pfelem->str) == '-') && (pfelem->flags & FLAG_ZERO_MASK))
	{
		pad_width -= 1;
		is_neg = 1;
		pfelem->str++;
	}
	pfelem->str = twl_strpad(pfelem->str, pad_width, pad_dir, fill_char);
	free(tmp);
	tmp = pfelem->str;
	if (is_neg)
	{
		pfelem->str = twl_strjoin("-", pfelem->str);
		free(tmp);
	}
}
