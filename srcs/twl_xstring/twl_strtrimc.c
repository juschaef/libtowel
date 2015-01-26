/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strtrimc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:11:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/26 17:47:35 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_xstring.h>
#include <twl_string.h>

char	*twl_strtrimc(char const *s, char *chars)
{
	int start;
	int end;

	if (!s)
		return (NULL);
	start = 0;
	end = twl_strlen(s) - 1;
	while (twl_strchr(chars, s[start]))
		start++;
	if (start >= end)
		return (twl_strdup(""));
	while (twl_strchr(chars, s[end]))
	{
		end--;
	}
	return (twl_strsub(s, start, end - start + 1));
}
