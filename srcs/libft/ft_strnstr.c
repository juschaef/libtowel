/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/08 19:10:51 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*twl_strnstr(const char *s1, const char *s2, size_t n)
{
	int found_last_char_pos;

	found_last_char_pos = twl_strstr(s1, s2) - s1 + twl_strlen(s2);
	if (found_last_char_pos > (int)n)
		return (NULL);
	return (twl_strstr(s1, s2));
}
