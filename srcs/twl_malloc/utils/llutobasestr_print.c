/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_stdlib.h"
#include "twl_xstdio.h"
#include "twl_string.h"
#include "twl_xstring.h"

#define MAX_CONVERTION_LENGTH 50

void				twl_llutobasestr_print(unsigned long long nbr, int base)
{
	char	hex[16];
	char	ret[MAX_CONVERTION_LENGTH];
	int		i;

	twl_strcpy(hex, "0123456789abcdef");
	i = 0;
	while (1)
	{
		ret[i++] = hex[nbr % base];
		nbr /= base;
		if (!nbr)
			break ;
	}
	ret[i] = 0;
	twl_strrev(ret);
	twl_putstr(ret);
}
