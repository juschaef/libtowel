/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutobasestr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:11:03 by yyang             #+#    #+#             */
/*   Updated: 2014/12/31 13:14:12 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#define MAX_CONVERTION_LENGTH 50

char	*ft_llutobasestr(unsigned long long nbr, int base)
{
	char	hex[16];
	char	*ret;
	int		i;

	ft_strcpy(hex, "0123456789abcdef");
	i = 0;
	ret = ft_strnew(MAX_CONVERTION_LENGTH);
	while (1)
	{
		ret[i++] = hex[nbr % base];
		nbr /= base;
		if (!nbr)
			break ;
	}
	ret[i] = 0;
	ft_strrev(ret);
	return (ret);
}
