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

char	*twl_strpad(const char *s, size_t min_width, char pad_dir, char c)
{
	size_t	len;
	char	*tab;

	len = twl_strlen(s);
	if (min_width <= len)
		return (twl_strdup(s));
	tab = twl_strnewc(min_width, c);
	if (pad_dir == FT_STRPAD_RIGHT)
		twl_memcpy(tab, s, len);
	else
		twl_memcpy(tab + min_width - len, s, len);
	return (tab);
}
