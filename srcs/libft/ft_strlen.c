/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 20:05:46 by yyang             #+#    #+#             */
/*   Updated: 2015/01/14 11:09:12 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int len;

	DEBUG_ASSERT(s != NULL);
	len = 0;
	while (s[len])
		len++;
	DEBUG_ASSERT(len <= FT_STRLEN_MAX_LEN);
	return (len);
}
