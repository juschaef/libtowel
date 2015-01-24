/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_wstr_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 18:01:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/08 16:23:46 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>
#include <stdlib.h>

char	*twl_wstr_to_str(wchar_t *wstr)
{
	char *str;
	char *wcharstr;

	str = twl_strnew(sizeof(wchar_t) * twl_wstrlen(wstr));
	if (!str)
		return (NULL);
	while (*wstr)
	{
		wcharstr = twl_wchar_to_str(*wstr++);
		str = twl_strcat(str, wcharstr);
		free(wcharstr);
	}
	return (str);
}
