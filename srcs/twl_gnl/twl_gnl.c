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

#include "twl_gnl.h"

static char		*twl_strchr_nl(const char *s)
{
	return (twl_strchr(s, '\n'));
}

static int		find_new_line(char **s_str, char **line, char *buf)
{
	twl_strcpy(*s_str, twl_strchr_nl(buf));
	twl_strncat(*line, buf, twl_strchr_nl(buf) - buf);
	twl_strcpy(*s_str, *s_str + 1);
	return (1);
}

static int		twl_read_buffer(int fd, char **s_str, char **line)
{
	int			ret;
	char		*temp;
	char		buf[GNL_BUFF_SIZE + 1];

	ret = 0;
	while ((ret = read(fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		if (ret < 0)
			return (-1);
		if (twl_memchr(buf, '\0', ret))
			return (GNL_ERR_BINARY_FILE);
		buf[ret] = '\0';
		if (!(temp = twl_strnew(twl_strlen(*line) + twl_strlen(buf))))
			return (-1);
		twl_strcpy(temp, *line);
		free(*line);
		*line = temp;
		if (twl_strchr_nl(buf))
		{
			return (find_new_line(s_str, line, buf));
		}
		twl_strcat(*line, buf);
	}
	return (ret < 0 ? -1 : 0);
}

static int		do_get_next_line(int const fd, char **line, char **remainder)
{
	int			ret;

	*line = twl_strnew(GNL_BUFF_SIZE + 1);
	*remainder = (!*remainder) ? twl_strnew(GNL_BUFF_SIZE + 1) : *remainder;
	if (!*line || !*remainder)
		return (-1);
	if (twl_strchr_nl(*remainder))
	{
		twl_strncpy(*line, *remainder, twl_strchr_nl(*remainder) - *remainder);
		twl_strcpy(*remainder, twl_strchr_nl(*remainder));
		twl_strcpy(*remainder, *remainder + 1);
		return (1);
	}
	twl_strcat(*line, *remainder);
	twl_bzero(*remainder, GNL_BUFF_SIZE + 1);
	ret = twl_read_buffer(fd, &*remainder, line);
	if (ret == 1 || ret < 0)
		return (ret);
	if (ret == 0 && twl_strlen(*line) == 0 && twl_strlen(*remainder) == 0)
		**line = '\0';
	if (twl_strlen(*line) > 0 || twl_strlen(*remainder) > 0)
		return (1);
	twl_strdel(line);
	return (0);
}

int				twl_gnl(int const fd, char **line, char **remainder)
{
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	ret = do_get_next_line(fd, line, remainder);
	if (ret <= 0)
	{
		free(*line);
		*line = NULL;
	}
	return (ret);
	(void)remainder;
}
