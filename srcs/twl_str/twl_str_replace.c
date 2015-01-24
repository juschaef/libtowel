/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 22:00:22 by yyang             #+#    #+#             */
/*   Updated: 2015/01/19 22:19:26 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char *twl_str_replace(char *s, char *target, char *replacement)
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
