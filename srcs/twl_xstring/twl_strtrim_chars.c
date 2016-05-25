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

#include "twl_xstring.h"
#include "twl_string.h"

char				*twl_strtrim_chars(char const *s, char *chars)
{
	int				start;
	int				end;
	char			*trimed;

	start = 0;
	end = twl_strlen(s) - 1;
	while (s[start] && twl_strchr(chars, s[start]))
		start++;
	while (s[start] && twl_strchr(chars, s[end]))
		end--;
	trimed = twl_strsub(s, start, end - start + 1);
	if (!trimed)
		return (twl_strdup(""));
	return (trimed);
}
