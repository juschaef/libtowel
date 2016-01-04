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
	if (twl_strlen(raw) == 0)
		return (original_val);
	if (raw[twl_strlen(raw) - 1] == '*')
		return (default_val);
	else if (raw && *raw)
		return (pfelem_get_last_digits_index(raw));
	return (original_val);
}
