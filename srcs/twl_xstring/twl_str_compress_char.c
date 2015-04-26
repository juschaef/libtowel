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
#include "twl_xstring.h"

char				*twl_str_compress_char(char *s, char c)
{
	char			tmp[twl_strlen(s) + 1];
	int				i;

	i = 0;
	while (*s)
	{
		tmp[i] = *s;
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			s++;
		}
		i++;
	}
	tmp[i] = 0;
	return (twl_strdup(tmp));
}
