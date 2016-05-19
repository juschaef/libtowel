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

#ifndef TWL_GNL_H
# define TWL_GNL_H

# include <unistd.h>
# include <stdlib.h>
# include "twl_string.h"
# include "twl_xstring.h"

# define GNL_BUFF_SIZE 8
# define GNL_ERR_BINARY_FILE -2

int					twl_gnl(int const fd, char **line, char **remainder);

#endif
