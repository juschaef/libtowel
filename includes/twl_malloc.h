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

#ifndef MALLOC_H
# define MALLOC_H

# include <stddef.h>

# include "twl_xstdio.h"

# include "twl_malloc/gmem.h"

# define CONST_N 128
# define CONST_M 1024
# define MIN_TINY_OCTET 1
# define MAX_TINY_OCTET CONST_N
# define MIN_SMALL_OCTET CONST_N + 1
# define MAX_SMALL_OCTET CONST_M
# define MIN_LARGE_OCTET CONST_M + 1
# define CONST_N_UP_PAGES 16
# define CONST_M_UP_PAGES 128
# define ZONE_NAME_TINY "TINY"
# define ZONE_NAME_SMALL "SMALL"
# define ZONE_NAME_LARGE "LARGE"

void				*twl_malloc(size_t size);
void				*twl_malloc_zero(size_t size);
void				*twl_malloc_exit(size_t size);
void				*twl_malloc_exit_zero(size_t size);
void				twl_free(void *addr);
void				twl_show_alloc_mem(void);
void				twl_clear_all_mallocs(void);
void				*twl_realloc(void *ptr, size_t size);

#endif
