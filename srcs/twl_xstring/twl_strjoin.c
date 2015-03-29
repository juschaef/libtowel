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

char	*twl_strjoin(char const *s1, char const *s2)
{
	char *s;
	char *save;

	s = (char *)malloc(sizeof(char) * (twl_strlen(s1) + twl_strlen(s2) + 1));
	if (!s)
		return (NULL);
	save = s;
	while (*s1 != '\0')
		*save++ = *s1++;
	while (*s2 != '\0')
		*save++ = *s2++;
	*save = '\0';
	return (s);
}
