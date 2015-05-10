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

char				*twl_str_split_get(char *str, char *split_chars, int index)
{
	char			**segs;
	char			*ret;

	segs = twl_strsplit_mul(str, split_chars);
	if (index < 0 || index > (int)twl_arr_len(segs) - 1)
		return (NULL);
	ret = twl_strdup(segs[index]);
	twl_arr_del(segs, free);
	return (ret);
}
