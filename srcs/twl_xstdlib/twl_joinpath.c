/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_joinpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:12:40 by annguyen          #+#    #+#             */
/*   Updated: 2015/01/30 16:13:10 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <twl_xstring.h>

char	*twl_joinpath(char *s1, char *s2)
{
	char	*s;

	s = twl_strjoin(s1, "/");
	s = twl_strjoinfree(s, s2, 'l');
	return (s);
}
