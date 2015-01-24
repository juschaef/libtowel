/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/02 23:03:12 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_llutoa(unsigned long long ln)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 50);
	if (!str)
		return (NULL);
	while (1)
	{
		str[i] = (ln % 10) + '0';
		ln = ln / 10;
		i++;
		if (ln == 0)
			break ;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
