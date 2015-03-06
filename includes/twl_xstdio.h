/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_xstdio.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 20:29:56 by yyang             #+#    #+#             */
/*   Updated: 2015/03/06 21:48:08 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_XSTDIO_H
# define TWL_XSTDIO_H

void	twl_putstr(char const *s);
void	twl_putstr_fd(char const *s, int fd);
void	twl_putchar_fd(char c, int fd);
int		twl_putchar_tty(int c);

#endif
