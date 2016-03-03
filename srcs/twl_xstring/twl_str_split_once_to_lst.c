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

#include <stdlib.h>
#include "twl_arr.h"
#include "twl_xstring.h"

t_lst				*twl_str_split_once_to_lst(char *str, char *chars)
{
	t_lst			*segs;
	char			*save;

	save = str;
	while (*str)
	{
		if (twl_strchr(chars, *str))
		{
			segs = twl_lst_new();
			twl_lst_push_back(segs, twl_strndup(save, str - save));
			twl_lst_push_back(segs, twl_strdup(str + 1));
			return (segs);
		}
		str++;
	}
	return (NULL);
}
