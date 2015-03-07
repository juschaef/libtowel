/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_isexec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:12:40 by annguyen          #+#    #+#             */
/*   Updated: 2015/03/07 15:04:16 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdbool.h>

bool		twl_isexec(char *path)
{
	struct stat st;

	if (lstat(path, &st) == -1)
		return (false);
	if (st.st_mode & S_IXGRP || st.st_mode & S_IXOTH || st.st_mode & S_IXUSR)
		return (true);
	return (false);
}
