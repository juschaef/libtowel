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
