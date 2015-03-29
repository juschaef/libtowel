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
#include "twl_stdio.h"

char	*twl_strtrimc(char const *s, char *chars)
{
	int start;
	int end;

	start = 0;
	end = twl_strlen(s) - 1;
	while (twl_strchr(chars, s[start]))
		start++;
	while (twl_strchr(chars, s[end]))
		end--;
	return (twl_strsub(s, start, end - start + 1));
}
