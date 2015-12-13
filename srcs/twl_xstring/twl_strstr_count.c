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

#include "twl_stdio.h"

size_t				twl_strstr_count(const char *s1, const char *s2)
{
	size_t			count;
	size_t			needle_len;

	count = 0;
	needle_len = twl_strlen(s2);
	if (needle_len == 0)
		return (0);
	while ((s1 = twl_strstr(s1, s2)))
	{
		// twl_printf("s1: {%s} s2: {%s} s1: {%s}\n", s1, s2, s1);
		count++;
		s1 += needle_len;
	}
	return (count);
}
