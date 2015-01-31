/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:10:46 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		twl_atoi(const char *str)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	while ((*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += (long)(*str - '0');
		str++;
	}
	if (((int)(value * sign) == 0 && value != 0) || (value < 0))
	{
		value = (sign < 0) ? 0 : -1;
	}
	return (int)(value * sign);
}
