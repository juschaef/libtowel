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

char	*twl_strnstr(const char *s1, const char *s2, size_t n)
{
	int found_last_char_pos;

	found_last_char_pos = twl_strstr(s1, s2) - s1 + twl_strlen(s2);
	if (found_last_char_pos > (int)n)
		return (NULL);
	return (twl_strstr(s1, s2));
}
