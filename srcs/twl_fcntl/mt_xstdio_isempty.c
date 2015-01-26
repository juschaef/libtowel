/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_xstdio_isempty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 22:12:40 by yyang             #+#    #+#             */
/*   Updated: 2015/01/26 17:39:27 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int mt_xstdio_is_file_empty(char *path)
{
	(void)path;
	return (0);
	// FILE *fp;

	// fp = fopen(path, "r");
	// long savedOffset = ftell(fp);
	// fseek(fp, 0, SEEK_END);

	// if (ftell(fp) == 0)
	// 	return (1);
	// fseek(fp, savedOffset, SEEK_SET);
	// fclose(fp);
	// return (0);
}
