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

#ifndef TWL_XSYS_STAT_H
# define TWL_XSYS_STAT_H

# include <stdbool.h>

bool			twl_isdir(char *path);
bool			twl_isdirl(char *path);
bool			twl_isexec(char *path);
bool			twl_isblock(char *path);
bool			twl_issocket(char *path);
bool			twl_isfifo(char *path);
bool			twl_isspec_char(char *path);
bool			twl_islink(char *path);
bool			twl_isdir(char *path);

#endif
