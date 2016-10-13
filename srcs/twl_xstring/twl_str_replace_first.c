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

static char	*get_first_occurence(char *str, char *old,
		size_t *size_str, size_t *size_old)
{
	size_t	index;
	char	*ret;

	index = 0;
	while (str[index])
	{
		*size_old = 0;
		while (str[index + *size_old] == old[*size_old] && old[*size_old])
			*size_old += 1;
		if (!old[*size_old])
			break ;
		index += 1;
	}
	if (!str[index])
		return (NULL);
	ret = str + index;
	while (str[index])
		index += 1;
	*size_str = index;
	return (ret);
}

static char	*inner_strncpy(char *dst, char *src, size_t length)
{
	while (length && *src)
	{
		*dst = *src;
		dst += 1;
		src += 1;
		length -= 1;
	}
	*dst = 0;
	return (dst);
}

static char	*inner_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		dst += 1;
		src += 1;
	}
	*dst = 0;
	return (dst);
}

char		*twl_str_replace_first(char *str, char *old, char *new)
{
	size_t	size_str;
	size_t	size_old;
	char	*first_occurence;
	char	*ret;
	char	*end;

	first_occurence = get_first_occurence(str, old, &size_str, &size_old);
	if (!first_occurence)
		return (twl_strdup(str));
	ret = twl_strnew(size_str - size_old + twl_strlen(new));
	end = inner_strncpy(ret, str, first_occurence - str);
	end = inner_strcpy(end, new);
	inner_strcpy(end, first_occurence + size_old);
	return (ret);
}
