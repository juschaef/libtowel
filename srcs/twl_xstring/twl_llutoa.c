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

#include <stdlib.h>
#include "twl_string.h"
#include "twl_xstring.h"

char	*twl_llutoa(unsigned long long ln)
{
	char	str[50];
	int		i;

	i = 0;
	twl_bzero(str, sizeof(str));
	while (1)
	{
		str[i] = (ln % 10) + '0';
		ln = ln / 10;
		i++;
		if (ln == 0)
			break ;
	}
	str[i] = '\0';
	twl_strrev(str);
	return (twl_strdup(str));
}
