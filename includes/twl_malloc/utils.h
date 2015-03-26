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

#ifndef UTILS_H
# define UTILS_H

typedef struct		s_tuple
{
	void			*t1;
	void			*t2;
}					t_tuple;

# define TP_UNPACK(ctx, var, arg_num) var = ((t_tuple *)ctx)->t ##arg_num;
# define TP2_NEW(arg1, arg2) (t_tuple){.t1 = arg1,.t2 = arg2};
# define TP2_UNPACK(ctx,v1,v2) TP_UNPACK(ctx,v1,1); TP_UNPACK(ctx,v2,2);

size_t				get_zone_size_by_name(char *name);
char				*twl_llutobasestr_print(unsigned long long nbr, int base);
void				print_colored_by_name(char *name);
void				print_zone_progress(t_zone *zone);
void				malloc_log(t_zone_mgr *zone_mgr, void *addr);
void				twl_llutobasestr_print_fd(unsigned long long nbr, int base,
																		int fd);
void				malloc_log_print(void);

#endif
