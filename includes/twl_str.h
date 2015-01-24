/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:05:35 by yyang             #+#    #+#             */
/*   Updated: 2015/01/19 22:13:20 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H
# include <stddef.h>

void	twl_str_replace_char(char *s, char target, char replacement);
char	*twl_str_replace(char *s, char *target, char *replacement);

#endif
