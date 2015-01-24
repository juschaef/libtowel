/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 22:00:22 by yyang             #+#    #+#             */
/*   Updated: 2015/01/19 22:19:26 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char *ft_str_replace(char *s, char *target, char *replacement)
{
	char *new_s;
	char *occ;

	new_s = ft_strdup("");
	while ((occ = ft_strstr(s, target)))
	{
		new_s = ft_strjoinfree(new_s, ft_strsub(s, 0, occ - s), 'b');
		new_s = ft_strjoinfree(new_s, replacement, 'l');
		s = occ + ft_strlen(target);
	}
	new_s = ft_strjoinfree(new_s, s, 'l');
	return (new_s);
}
