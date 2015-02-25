/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:35:27 by juschaef          #+#    #+#             */
/*   Updated: 2015/02/24 15:36:40 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>

int		term_width(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}
