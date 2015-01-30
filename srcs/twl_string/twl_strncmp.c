/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:12:10 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		twl_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((n == 0) || (!s1 && !s2))
		return (0);
	while (*s1 == *s2)
	{
		if (*s1 == 0 || --n == 0)
			return (0);
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}
