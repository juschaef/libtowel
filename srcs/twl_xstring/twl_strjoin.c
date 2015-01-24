/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/13 15:11:55 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_string.h>
#include <stdlib.h>

char	*twl_strjoin(char const *s1, char const *s2)
{
	char *s;
	char *save;

	s = (char *)malloc(sizeof(char) * (twl_strlen(s1) + twl_strlen(s2) + 1));
	if (!s)
		return (NULL);
	save = s;
	while (*s1 != '\0')
		*save++ = *s1++;
	while (*s2 != '\0')
		*save++ = *s2++;
	*save = '\0';
	return (s);
}
