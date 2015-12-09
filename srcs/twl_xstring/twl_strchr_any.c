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

#include "twl_xstring.h"

char				*twl_strchr_any(const char *haystack, const char *needles)
{
	if (*needles == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (twl_strchr(needles, *haystack))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
