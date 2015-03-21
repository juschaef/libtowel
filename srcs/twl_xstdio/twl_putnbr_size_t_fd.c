/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_putnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 18:08:45 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "twl_xstdio.h"

void				twl_putnbr_size_t_fd(size_t n, int fd)
{
	if (n > 9)
		twl_putnbr_size_t_fd(n / 10, fd);
	twl_putchar_fd((char)(n % 10 + 48), fd);
}
