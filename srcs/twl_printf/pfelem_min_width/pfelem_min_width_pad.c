/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_min_width_pad.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:34:05 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:35:44 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

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
