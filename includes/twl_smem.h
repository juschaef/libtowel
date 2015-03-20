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

#ifndef TWL_SMEM_H
# define TWL_SMEM_H

# include <stddef.h>

typedef enum		e_twl_smem
{
	TWL_SMEM_TYPE_LST
}					t_twl_smem;

void				*twl_smem_get(t_twl_smem type);
void				twl_smem_err_overflow(char *msg);
void				*twl_smem_type_lst(void);
void				*twl_smem_type_lst_elem__(void);

#endif
