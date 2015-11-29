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

char				*twl_str_before_any_char(const char *src, const char *chars)
{
	char			*pos;
	char			*new_str;
	size_t			len;

	pos = twl_strchr_any(src, chars);
	if (!pos)
		return (NULL);
	len = pos - src;
	new_str = twl_strnew(len);
	twl_strncpy(new_str, src, len);
	return (new_str);
}
