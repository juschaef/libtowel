/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:11:34 by yyang             #+#    #+#             */
/*   Updated: 2014/12/28 10:20:25 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	int start;
	int end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == c)
		start++;
	if (start >= end)
		return (ft_strdup(""));
	while (s[end] == c)
	{
		end--;
	}
	return (ft_strsub(s, start, end - start + 1));
}
