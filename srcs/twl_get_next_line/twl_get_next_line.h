/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:37:49 by yyang             #+#    #+#             */
/*   Updated: 2014/12/29 19:49:21 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define MAX_BUFF_SIZE 8385531
# define MAX_PARALLEL_FILES 100000

# include <unistd.h>
# include <twl_string.h>

int get_next_line(int const fd, char **line);

#endif
