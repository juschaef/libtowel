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

#include "twl_string.h"

char	*twl_strstr(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (NULL);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		if (twl_memcmp(s1, s2, twl_strlen(s2)) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
