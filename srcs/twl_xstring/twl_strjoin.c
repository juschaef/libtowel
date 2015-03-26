/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:14:16 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_string.h"

char	*twl_strjoin(char const *s1, char const *s2)
{
	char *s;
	char *save;

	s = (char *)twl_malloc(sizeof(char) * (twl_strlen(s1) + twl_strlen(s2) + 1));
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
