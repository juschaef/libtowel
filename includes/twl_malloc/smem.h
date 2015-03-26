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

#ifndef SMEM_H
# define SMEM_H

typedef enum		e_smem
{
	STATIC_MEM_ZONE_MGR,
	STATIC_MEM_ZONE,
	STATIC_MEM_MSEG
}					t_smem;

void				*smem_get(t_smem type);
void				smem_err_overflow(char *msg);
void				*static_mem_zone_mgr(void);
void				*static_mem_zone(void);
void				*static_mem_mseg(void);

#endif
