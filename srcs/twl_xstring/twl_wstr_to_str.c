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
