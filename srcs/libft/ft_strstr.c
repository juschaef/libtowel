/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/12/12 14:46:53 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (NULL);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		if (ft_memcmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
