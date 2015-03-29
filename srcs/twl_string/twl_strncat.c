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

char	*twl_strncat(char *s1, const char *s2, size_t n)
{
	char	*save;
	size_t	i;

	if (!s1 || !s2)
		return (void *)0;
	save = s1;
	i = 0;
	while (*s1)
		s1++;
	while (*s2 && i++ < n)
		*s1++ = *s2++;
	*s1 = '\0';
	return (save);
}
