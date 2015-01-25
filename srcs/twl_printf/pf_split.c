/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:12:23 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 11:39:23 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_printf.h>

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
		twl_lst_push(lst, tmp);
		s = s + twl_strlen(tmp);
		if (!*s)
			break ;
	}
	return (lst);
}
