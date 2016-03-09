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

#include "twl_printf.h"

static char	*pf_get_seg(char *s)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (!twl_strchr(VALID_CHARS_BEFORE_CONV_SPEC, s[i]))
			break ;
		i++;
	}
	if ((*s == '%') && s[i])
		i++;
	return (twl_strsub(s, 0, i));
}

t_lst		*pf_split(char *s)
{
	t_lst	*lst;
	char	*tmp;

	lst = twl_lst_new();
	while (1)
	{
		tmp = pf_get_seg(s);
		twl_lst_push_back(lst, tmp);
		s = s + twl_strlen(tmp);
		if (!*s)
			break ;
	}
	return (lst);
}
