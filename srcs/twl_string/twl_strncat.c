/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:12:07 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*twl_strncat(char *s1, const char *s2, size_t n)
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
