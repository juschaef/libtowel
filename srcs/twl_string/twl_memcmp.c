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
