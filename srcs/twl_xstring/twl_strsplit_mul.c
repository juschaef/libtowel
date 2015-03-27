/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/02/02 17:48:50 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twl_string.h"
#include "twl_xstring.h"
#include "twl_stdio.h"

static int		twl_count_words(const char *s, char *c)
{
	int		count;
	int		insub;

	insub = 0;
	count = 0;
	while (*s != '\0')
	{
		if (insub == 1 && twl_strchr(c, *s))
			insub = 0;
		else if (insub == 0 && !twl_strchr(c, *s))
		{
			insub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		twl_wordlen(const char *s, char *c)
{
	int		len;

	len = 0;
	while (!twl_strchr(c, *s) && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**twl_strsplit_mul(char const *s, char *c)
{
	char	**t;
	int		word_count;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	word_count = twl_count_words(s, c);
	t = (char **)malloc(sizeof(*t) * (word_count + 1));
	if (t == NULL)
		return (NULL);
	while (word_count--)
	{
		while (twl_strchr(c, *s) && *s != '\0')
			s++;
		t[index] = twl_strsub(s, 0, twl_wordlen(s, c));
		if (t[index] == NULL)
			return (NULL);
		s = s + twl_wordlen(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
