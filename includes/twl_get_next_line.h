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

#ifndef TWL_GET_NEXT_LINE_H
# define TWL_GET_NEXT_LINE_H

# include <unistd.h>
# include "twl_string.h"

# define BUFF_SIZE 8
# define MAX_BUFF_SIZE 8385531
# define MAX_PARALLEL_FILES 100000

int					twl_get_next_line(int const fd, char **line);
int					twl_get_next_line_v2(int const fd, char **line, char **remainder);

#endif
