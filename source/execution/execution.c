/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:28:03 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/19 16:02:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"
#include "utils/shell_utils.h"
#include "builtins/builtins.h"
#include "environment/environment.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>

static int	fork_and_execute(const char **args)
{
	int	status;

	g_shell.process = fork();
	if (g_shell.process == 0)
	{
		execve(args[0], args + 1, g_shell.env);
		g_shell.is_running = false;
		return (SUCCESS);
	}
	else
	{
		wait(&status);
		g_shell.process = 0;
	}
	return (SUCCESS);
}

static int	try_execute_builtin(const char **args)
{
	int i;

	i = 0;
	while (i < g_builtins_size)
	{
		if (ft_strcmp(g_builtins_names[i], args[0]) == 0)
		{
			return (g_builtin_funcs[i](args + 1));
		}
		++i;
	}
	return (NO_SUCH_BINARY);
}

static int	try_execute_global_binary(const char **args)
{
	int		status;
	int		i;
	char	**paths;
	char	*path;

	path = get_environment(PATH_VAR);
	if (!path)
		return (NO_PATH_VAR);
	paths = ft_strsplit(path, ':');
	free(path);
	i = 0;
	status = PERMISIION_DENIED;
	while (paths[i] && status != SUCCESS)
	{
		path = ft_strs_join_c(paths[i], args[0], '/');
		if (access(path, X_OK) == 0)
			status = fork_and_execute(path, args + 1);
		free(path);
		++i;
	}
	ft_splitdel(paths);
	return (status);
}

static int	try_execute_local_binary(const char **args)
{
	int		status;
	char	*pwd;
	char	*full_path;

	status = PERMISIION_DENIED;
	pwd = get_environment(PWD_VAR);
	if (!pwd)
		return (NO_PWD_VAR);
	path = ft_strs_join_c(pwd, args[0], '/');
	if (access(path, F_OK) != 0)
		return (NO_SUCH_BINARY);
	if (access(path, X_OK) == 0)
		status = fork_and_execute(path, args + 1);
	free(pwd);
	free(path);
	return (status);
}

int			execute_command(const char **args)
{
	int		status;

	if (!args)
		return (SUCCESS);
	status = try_execute_builtin(args);
	if (status != NO_SUCH_BINARY)
		return (status);
	status = try_execute_global_binary(args);
	if (status != NO_SUCH_BINARY)
		return (status);
	return (try_execute_local_binary(args));
}
