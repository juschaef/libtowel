/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_get_next_line.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:37:49 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 22:52:43 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWL_GET_NEXT_LINE_H
# define TWL_GET_NEXT_LINE_H

# include <unistd.h>
# include "twl_string.h"

# define BUFF_SIZE 8
# define MAX_BUFF_SIZE 8385531
# define MAX_PARALLEL_FILES 100000

int twl_get_next_line(int const fd, char **line);

#endif
