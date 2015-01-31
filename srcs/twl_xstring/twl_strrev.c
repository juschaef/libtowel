/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 23:00:22 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:14:34 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	twl_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char			*twl_strrev(char *str)
{
	int				j;
	int				i;
	unsigned char	a;
	unsigned		len;

	len = twl_strlen((const char *)str);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		i++;
		j--;
	}
	return (str);
}
