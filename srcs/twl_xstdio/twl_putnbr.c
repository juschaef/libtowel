/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/03/04 19:58:05 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "twl_stdio.h"

/*
** print number 'n' to file descriptor 1
** works with minimum int and negatives
*/

void	twl_putnbr(int n)
{
	if (n < 0)
	{
		twl_putchar('-');
		if (n < -9)
		{
			twl_putnbr(n / 10 * -1);
		}
		twl_putchar((char)(n % 10 * -1 + 48));
	}
	else
	{
		if (n > 9)
		{
			twl_putnbr(n / 10);
		}
		twl_putchar((char)(n % 10 + 48));
	}
}
