/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_simple_getopt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 17:19:25 by emaniez           #+#    #+#             */
/*   Updated: 2015/02/16 16:48:24 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_getopt.h"

/*
** A simple version of getopt, which integrates single and multiple-letter
** option blocks.
** Does not (yet) integrate option arguments.
** If character is not part of optstr, optopt points to that character.
** If return is -1, optopt is set to the first post-option character.
*/

int	spaces(int *i, int *j, char **optopt, const char **av)
{
	if (!av[*i][*j])
	{
		(*i)++;
		*j = 0;
		if (!av[*i] || av[*i][*j] != '-')
		{
			*optopt = (char*)&av[*i][*j];
			return (-1);
		}
	}
	return (0);
}

int	double_hyphen(int *i, int *j, char **optopt, const char **av)
{
	if (av[*i][*j] == '-')
	{
		if (!av[*i][*j + 1])
		{
			*optopt = (char*)&av[*i][*j];
			return (-1);
		}
		(*j)++;
		if (av[*i][*j] == '-')
		{
			if (av[*i][*j + 1])
			{
				while (av[*i][*j + 1] == '-')
					(*j)++;
				return (0);
			}
			*optopt = (char*)&av[++*i][0];
			return (-1);
		}
	}
	return (0);
}

int	error_return(int *hyphen, int *i, int *j)
{
	*hyphen = 0;
	*i = 1;
	*j = 0;
	return (-1);
}

int	opening_hyphen(const char **av, int *hyphen)
{
	if (*hyphen == 1)
		return (1);
	if (av[1][0] == '-')
	{
		*hyphen = 1;
		return (1);
	}
	return (0);
}

int	twl_simple_getopt(const char **av, const char *optstr, char **optopt)
{
	static int	hyphen = 0;
	static int	i = 1;
	static int	j = 0;

	if (!av || !av[1] || !optstr || !optopt)
		return (error_return(&hyphen, &i, &j));
	*optopt = (char*)&av[i][j];
	if (!opening_hyphen(av, &hyphen))
		return (error_return(&hyphen, &i, &j));
	if (spaces(&i, &j, optopt, av) == -1)
		return (error_return(&hyphen, &i, &j));
	if (double_hyphen(&i, &j, optopt, av) == -1)
		return (error_return(&hyphen, &i, &j));
	*optopt = (char*)&av[i][j];
	j++;
	if (!twl_strchr(optstr, av[i][j - 1]))
		return ('?');
	return (av[i][j - 1]);
}
