/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 16:16:43 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 18:08:14 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*twl_strpad(const char *s, size_t min_width, int pad_dir, char c)
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
