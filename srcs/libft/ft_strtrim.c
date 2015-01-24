/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/24 13:33:18 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_local_isblank(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (ft_local_isblank(s[start]))
		start++;
	while (ft_local_isblank(s[end - 1]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	return (ft_strsub(s, start, end - start));
}
