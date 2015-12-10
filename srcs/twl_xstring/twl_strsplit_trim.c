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
#include "twl_stdio.h"

static int		twl_count_words(const char *s, char c)
{
	int		count;
	int		insub;

	insub = 0;
	count = 0;
	while (*s != '\0')
	{
		if (insub == 1 && *s == c)
			insub = 0;
		else if (insub == 0 && *s != c)
		{
			insub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		twl_wordlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**twl_strsplit_trim_chars(char const *s, char split_char,
															char *trim_chars)
{
	char	**t;
	int		word_count;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	word_count = twl_count_words(s, split_char);
	t = (char **)malloc(sizeof(*t) * (word_count + 1));
	if (t == NULL)
		return (NULL);
	while (word_count--)
	{
		while (*s == split_char && *s != '\0')
			s++;
		t[index] = twl_strtrim_chars_free(
			twl_strsub(s, 0, twl_wordlen(s, split_char)), trim_chars);
		if (t[index] == NULL)
			return (NULL);
		s = s + twl_wordlen(s, split_char);
		index++;
	}
	t[index] = NULL;
	return (t);
}
