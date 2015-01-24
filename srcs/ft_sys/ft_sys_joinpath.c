/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_joinpath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:12:40 by annguyen          #+#    #+#             */
/*   Updated: 2015/01/20 22:10:24 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>

char	*ft_sys_joinpath(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, "/");
	s = ft_strjoinfree(s, s2, 'l');
	return (s);
}