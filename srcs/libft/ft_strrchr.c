/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/13 11:19:38 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char			*ft_strrchr(const char *s, int c)
{
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (len >= 0 && s[len] != (char)c)
		len--;
	if (s[len] == (char)c)
		return ((char*)&s[len]);
	return (NULL);
}
