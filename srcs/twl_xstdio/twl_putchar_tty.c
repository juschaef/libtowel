/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_putchar_tty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 16:39:07 by gbarraul          #+#    #+#             */
/*   Updated: 2015/03/06 18:15:59 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

/*
** print char 'c' to file descriptor 'fd'
*/

int		twl_putchar_tty(int c)
{
	int fd;
	int ret;

	fd = open("/dev/tty", O_WRONLY);
	ret = write(fd, &c, 1);
	close(fd);
	return (ret);
}
