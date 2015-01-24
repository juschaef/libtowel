/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_ctype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:05:35 by yyang             #+#    #+#             */
/*   Updated: 2015/01/24 20:34:33 by yyang            ###   ########.fr       */
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

#endif
