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
#include "twl_xstring.h"

char	*twl_str_replace(char *s, char *target, char *replacement)
{
	char *new_s;
	char *occ;

	new_s = twl_strdup("");
	while ((occ = twl_strstr(s, target)))
	{
		new_s = twl_strjoinfree(new_s, twl_strsub(s, 0, occ - s), 'b');
		new_s = twl_strjoinfree(new_s, replacement, 'l');
		s = occ + twl_strlen(target);
	}
	new_s = twl_strjoinfree(new_s, s, 'l');
	return (new_s);
}
