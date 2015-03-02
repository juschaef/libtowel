/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_wchar_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 18:01:50 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:14:36 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "twl_string.h"
#include "twl_xstring.h"

static int	nbits(unsigned int nbr)
{
	int	i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

static int	get_nbytes(unsigned int nbr)
{
	int n;

	n = nbits(nbr);
	if (n < 8)
		return (1);
	else if (n < 12)
		return (2);
	else if (n < 17)
		return (3);
	else
		return (4);
}

char		*twl_wchar_to_str(wchar_t wstr)
{
	int				nbytes;
	char			*bytes;
	unsigned int	ch;

	ch = wstr;
	nbytes = get_nbytes(ch);
	bytes = twl_strnew(nbytes);
	if (nbytes == 1)
		bytes[0] = ch;
	if (nbytes >= 2)
	{
		bytes[0] = ((ch >> 6 * 0) & 63) | 128;
		bytes[1] = ((ch >> 6 * 1) & 31) | 192;
	}
	if (nbytes >= 3)
	{
		bytes[1] = ((ch >> 6 * 1) & 63) | 128;
		bytes[2] = ((ch >> 6 * 2) & 15) | 224;
	}
	if (nbytes >= 4)
	{
		bytes[2] = ((ch >> 6 * 2) & 63) | 128;
		bytes[3] = ((ch >> 6 * 3) & 7) | 240;
	}
	return (twl_strrev(bytes));
}
