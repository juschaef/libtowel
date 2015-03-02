/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strpad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 16:16:43 by yyang             #+#    #+#             */
/*   Updated: 2015/02/02 16:24:12 by annguyen         ###   ########.fr       */
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
