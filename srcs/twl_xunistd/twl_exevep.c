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

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "twl_arr.h"
#include "twl_xstring.h"
#include "twl_xstdlib.h"

#define PATH_KEY_PREFIX "PATH="

static int			is_local_executable(char *original_cmd_path)
{
	int				is_file;

	is_file = (access(original_cmd_path, F_OK) != -1
		&& access(original_cmd_path, X_OK) != -1);
	return (is_file);
}

static bool			is_path_env_fn(void *env_str, void *context)
{
	return (twl_strnequ(env_str, PATH_KEY_PREFIX, twl_strlen(PATH_KEY_PREFIX)));
	(void)context;
}

static char			**get_paths(char *envp[])
{
	char			*env;
	char			**env_segs;
	char			**paths;

	env = twl_arr_find(envp, is_path_env_fn, NULL);
	env_segs = twl_strsplit(env, '=');
	paths = twl_strsplit(env_segs[1], ':');
	twl_arr_del(env_segs, free);
	return (paths);
}

static bool			has_executable_binary_fn(void *path, void *file)
{
	char			*fullpath;
	bool			is_exec;

	fullpath = twl_joinpath(path, file);
	is_exec = is_local_executable(fullpath);
	free(fullpath);
	return (is_exec);
}

int					twl_execvep(char *file, char **argv, char **envp)
{
	char			**paths;
	char			*found_path;

	paths = get_paths(envp);
	found_path = twl_arr_find(paths, has_executable_binary_fn, file);
	if (found_path)
		file = twl_joinpath(found_path, file);
	return (execve(file, argv, envp));
}
