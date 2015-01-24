/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2014/11/12 23:29:18 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		twl_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *uc_s1;
	unsigned char *uc_s2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*uc_s1 != *uc_s2)
			return ((unsigned char)*uc_s1 - (unsigned char)*uc_s2);
		uc_s1++;
		uc_s2++;
	}
	return (0);
}
