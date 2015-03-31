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

#include "twl_stdio.h"
#include "twl_ctype.h"

static long long	power_ten(int power)
{
	long long		power_ten;

	power_ten = 1;
	while (power > 0)
	{
		power_ten *= 10;
		power--;
	}
	return (power_ten);
}

double				twl_atof(const char *s)
{
	double			result;
	long long int	res_int;
	int				power;
	int				sign;

	result = 0;
	power = 0;
	res_int = 0;
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s != '\0' && twl_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	if (*s++ == '.')
		while (*s != '\0' && twl_isdigit(*s))
		{
			res_int = res_int * 10 + (*s - '0');
			power = power + 1;
			s++;
		}
	result += res_int / (power_ten(power) * 1.0);
	return (result * sign);
}
