/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_putchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 16:39:07 by gbarraul          #+#    #+#             */
/*   Updated: 2015/03/02 18:08:00 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** print char 'c' to file descriptor 'fd'
*/

void	twl_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
