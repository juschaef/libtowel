/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_wstr_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 18:01:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:14:37 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include "twl_string.h"
#include "twl_xstring.h"

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
