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

#include <stddef.h>

char			*twl_strrchr(const char *s, int c)
{
	char		*ret;

	ret = NULL;
	while (1)
	{
		if (*s == c)
		{
			ret = (char *)s;
		}
		if (*s == 0)
		{
			break ;
		}
		s += 1;
	}
	return (ret);
}
