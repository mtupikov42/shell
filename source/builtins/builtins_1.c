/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:26:26 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:04:27 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtins.h"
#include "utils/shell_utils.h"
#include "utils/environment_utils.h"
#include "environment/environment.h"
#include "shell.h"
#include "libft.h"

int	bt_echo(const char **args)
{
	char	*str;
	char	*result;

	if (!args || !args[0])
	{
		ft_printf("\n");
		return (SUCCESS);
	}
	str = ft_split_join_delimiter(args, " ");
	result = replace_environment_variables(str);
	safe_free(str);
	if (!result)
		return (ERROR);
	ft_printf("%s\n", result);
	safe_free(result);
	return (SUCCESS);
}

int	bt_cd(const char **args)
{
	(void)args;
	return (SUCCESS);
}

int	bt_setenv(const char **args)
{
	char	**split;
	int		args_len;
	int		status;

	args_len = ft_strsplit_count((char **)args);
	if ((args_len != 3 && args_len != 1)
		|| (args_len == 3 && ft_strlen(args[1]) == 1 && *args[1] != '='))
		return (SETENV_SYNTAX_ERROR);
	if (args_len == 3)
		return (set_environment((char *)args[0], (char *)args[2]));
	split = ft_strsplit((char *)args[0], '=');
	if (ft_strsplit_count(split) != 2)
	{
		ft_splitdel(&split);
		return (SETENV_SYNTAX_ERROR);
	}
	status = set_environment(split[0], split[1]);
	ft_splitdel(&split);
	return (status);
}

int	bt_unsetenv(const char **args)
{
	int	i;
	int	status;
	int	error_status;

	error_status = SUCCESS;
	if (ft_strsplit_count((char **)args) == 0)
		return (UNSETENV_ARGS_ERROR);
	i = 0;
	while (args[i])
	{
		status = unset_environment((char *)args[i]);
		if (status != SUCCESS)
			error_status = status;
		++i;
	}
	return (error_status);
}

int	bt_env(const char **args)
{
	int		i;

	(void)args;
	i = 0;
	while (g_shell.env[i])
	{
		ft_printf("%s\n", g_shell.env[i]);
		++i;
	}
	return (SUCCESS);
}
