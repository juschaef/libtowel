/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 18:05:39 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#define FT_LDTOA_PRECISION 7
#define FT_LDTOA_PRECISION_MULT 1000000

char	*ft_ldtoa(long double ld)
{
	int			is_neg;
	char		*str;
	char		*tmp;
	char		first[20];

	is_neg = 0;
	if (ld < 0)
	{
		is_neg = 1;
		ld = -ld;
	}
	str = ft_llutoa((long long)(ld * FT_LDTOA_PRECISION_MULT));
	tmp = str;
	str = ft_strpad(str, FT_LDTOA_PRECISION, FT_STRPAD_LEFT, '0');
	free(tmp);
	ft_bzero(first, 20);
	ft_strncpy(first, str, ft_strlen(str) - 6);
	tmp = ft_strjoin(first, ".");
	tmp = ft_strjoinfree(tmp, str + ft_strlen(first), 'l');
	free(str);
	if (is_neg)
		tmp = ft_strjoinfree("-", tmp, 'r');
	return (tmp);
}
