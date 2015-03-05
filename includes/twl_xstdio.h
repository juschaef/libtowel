/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_xstdio.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 20:29:56 by yyang             #+#    #+#             */
/*   Updated: 2015/03/04 19:55:27 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_XSTDIO_H
# define TWL_XSTDIO_H

void	twl_putstr(char const *s);
void	twl_putstr_fd(char const *s, int fd);
void	twl_putchar_fd(char c, int fd);

#endif
