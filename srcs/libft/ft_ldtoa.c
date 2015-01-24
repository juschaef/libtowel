/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_ldtoa.c                                         :+:      :+:    :+:   */
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

char	*twl_ldtoa(long double ld)
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
	str = twl_llutoa((long long)(ld * FT_LDTOA_PRECISION_MULT));
	tmp = str;
	str = twl_strpad(str, FT_LDTOA_PRECISION, FT_STRPAD_LEFT, '0');
	free(tmp);
	twl_bzero(first, 20);
	twl_strncpy(first, str, twl_strlen(str) - 6);
	tmp = twl_strjoin(first, ".");
	tmp = twl_strjoinfree(tmp, str + twl_strlen(first), 'l');
	free(str);
	if (is_neg)
		tmp = twl_strjoinfree("-", tmp, 'r');
	return (tmp);
}
