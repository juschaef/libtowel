/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 18:08:27 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "twl_xstdio.h"

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
