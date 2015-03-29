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

int		twl_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((n == 0) || (!s1 && !s2))
		return (0);
	while (*s1 == *s2)
	{
		if (*s1 == 0 || --n == 0)
			return (0);
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}
