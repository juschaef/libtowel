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
#include "twl_xstdio.h"

/*
** print number 'n' to file descriptor 'fd'
** works with minimum int and negatives
*/

void	twl_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		twl_putchar_fd('-', fd);
		if (n < -9)
		{
			twl_putnbr_fd(n / 10 * -1, fd);
		}
		twl_putchar_fd((char)(n % 10 * -1 + 48), fd);
	}
	else
	{
		if (n > 9)
		{
			twl_putnbr_fd(n / 10, fd);
		}
		twl_putchar_fd((char)(n % 10 + 48), fd);
	}
}
