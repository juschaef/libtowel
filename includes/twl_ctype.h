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

#ifndef TWL_CTYPE_H
# define TWL_CTYPE_H

int					twl_isalnum(int c);
int					twl_isalpha(int c);
int					twl_isascii(int c);
int					twl_isblank(int c);
int					twl_isdigit(int c);
int					twl_islower(int c);
int					twl_isprint(int c);
int					twl_ispunct(int c);
int					twl_isspace(int c);
int					twl_isupper(int c);
int					twl_tolower(int c);
int					twl_toupper(int c);
int					twl_iscntrl(int c);
int					twl_isxdigit(int c);

#endif
