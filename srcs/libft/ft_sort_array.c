/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 10:16:34 by juschaef          #+#    #+#             */
/*   Updated: 2015/01/14 13:27:56 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void		strswap(char **s1, char **s2)
{
	char	*temp;

	temp = ft_strdup(*s1);
	free(*s1);
	*s1 = ft_strdup(*s2);
	free(*s2);
	*s2 = temp;
}

static int		partition(char **s, int l, int h)
{
	int		i;
	int		p;
	int		firsthight;

	p = h;
	firsthight = l;
	i = l;
	while (i < h)
	{
		if (ft_strcmp(s[i], s[p]) < 0)
		{
			strswap(&s[i], &s[firsthight]);
			firsthight++;
		}
		i++;
	}
	strswap(&s[p], &s[firsthight]);
	return (firsthight);
}

static void		quick_sort(char **s, int l, int h)
{
	int p;

	if ((h - l) > 0)
	{
		p = partition(s, l, h);
		quick_sort(s, l, p - 1);
		quick_sort(s, p + 1, h);
	}
}

void			ft_sort_array(char **s, int size)
{
	if (size == 1 || size == 0)
		return ;
	quick_sort(s, 0, size - 1);
}
