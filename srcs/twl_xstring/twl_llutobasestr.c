/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_llutobasestr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:11:03 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:37:40 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_string.h"
#include "twl_xstring.h"

#define MAX_CONVERTION_LENGTH 50

char	*twl_llutobasestr(unsigned long long nbr, int base)
{
	char	hex[16];
	char	*ret;
	int		i;

	twl_strcpy(hex, "0123456789abcdef");
	i = 0;
	ret = twl_strnew(MAX_CONVERTION_LENGTH);
	while (1)
	{
		ret[i++] = hex[nbr % base];
		nbr /= base;
		if (!nbr)
			break ;
	}
	ret[i] = 0;
	twl_strrev(ret);
	return (ret);
}
