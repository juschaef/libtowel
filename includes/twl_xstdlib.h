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

#ifndef TWL_XSTDLIB_H
# define TWL_XSTDLIB_H

char				*twl_joinpath(char *s1, char *s2);
void				*twl_xmalloc(int size);
void				*twl_malloc_x0(int size);
int					twl_rand(void);
int					twl_randint(int start, int end);
int					twl_clockrand(void);
#endif
