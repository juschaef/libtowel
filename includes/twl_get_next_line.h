/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_get_next_line.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:37:49 by yyang             #+#    #+#             */
/*   Updated: 2015/01/30 16:43:14 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_GET_NEXT_LINE_H
# define TWL_GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define MAX_BUFF_SIZE 8385531
# define MAX_PARALLEL_FILES 100000

# include <unistd.h>
# include <twl_string.h>

int twl_get_next_line(int const fd, char **line);

#endif
