/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfelem_get_value_or_wildcard.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:12:41 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 18:18:00 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

static int		pfelem_get_last_digits_index(char *raw)
{
	int i;

	i = twl_strlen(raw) - 1;
	while (i >= 0)
	{
		if (!twl_isdigit(raw[i]))
			break ;
		i--;
	}
	i++;
	return (twl_atoi(&(raw[i])));
}

int				pfelem_get_value_or_wildcard(char *raw, int default_val,
											int original_val)
{
	if (raw[twl_strlen(raw) - 1] == '*')
		return (default_val);
	else if (raw && *raw)
		return (pfelem_get_last_digits_index(raw));
	return (original_val);
}
