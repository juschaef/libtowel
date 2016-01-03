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

#include "twl_string.h"
#include "twl_xstring.h"

char				*twl_str_truncate(char *str, size_t len)
{
	char			*truncated_str;

	if (twl_strlen(str) > len)
	{
		if (len > 3)
		{
			truncated_str = twl_strnew(len);
			twl_strncat(truncated_str, str, len - 3);
			twl_strcat(truncated_str, "...");
		}
		else
		{
			truncated_str = twl_strndup(str, len);
		}
	}
	else
	{
		truncated_str = twl_strdup(str);
	}
	return (truncated_str);
}
