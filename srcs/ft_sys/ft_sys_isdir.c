/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_isdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annguyen <annguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:12:40 by annguyen          #+#    #+#             */
/*   Updated: 2015/01/20 21:20:23 by annguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int        ft_sys_isdir(char *path)
{
    struct stat st;

    lstat(path, &st);
    return (S_ISDIR(st.st_mode));
}