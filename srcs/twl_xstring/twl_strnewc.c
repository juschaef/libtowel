/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_strnewc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:38:18 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <twl_string.h>
#include <stdlib.h>

char			*twl_strnewc(size_t size, char c)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	twl_memset(new, c, size);
	new[size] = '\0';
	return (new);
}
