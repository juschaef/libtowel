/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_llutoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:37:29 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <twl_string.h>
#include <twl_xstring.h>
#include <stdlib.h>

char	*twl_llutoa(unsigned long long ln)
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
	return (twl_strrev(str));
}