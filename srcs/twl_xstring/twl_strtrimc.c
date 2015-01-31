/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strtrimc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:11:34 by yyang             #+#    #+#             */
/*   Updated: 2015/01/31 15:13:34 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_xstring.h>
#include <twl_string.h>
#include <twl_stdio.h>

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
