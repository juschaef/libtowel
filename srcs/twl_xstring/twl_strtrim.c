/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:44:27 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <twl_xstring.h>

static int		twl_local_isblank(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char			*twl_strtrim(char const *s)
{
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	end = twl_strlen(s);
	while (twl_local_isblank(s[start]))
		start++;
	while (twl_local_isblank(s[end - 1]))
		end--;
	if (start >= end)
		return (twl_strdup(""));
	return (twl_strsub(s, start, end - start));
}
