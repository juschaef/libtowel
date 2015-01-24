/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/12 23:30:44 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*save;
	size_t	i;

	if (!s1 || !s2)
		return (void *)0;
	save = s1;
	i = 0;
	while (*s1)
		s1++;
	while (*s2 && i++ < n)
		*s1++ = *s2++;
	*s1 = '\0';
	return (save);
}
