/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:12:52 by annguyen          #+#    #+#             */
/*   Updated: 2015/03/07 15:03:52 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_XSYS_STAT_H
# define TWL_XSYS_STAT_H

# include <stdbool.h>

bool			twl_isdir(char *path);
bool			twl_isexec(char *path);
bool			twl_isblock(char *path);
bool			twl_issocket(char *path);
bool			twl_isfifo(char *path);
bool			twl_isspec_char(char *path);
bool			twl_islink(char *path);
bool			twl_isdir(char *path);

#endif
