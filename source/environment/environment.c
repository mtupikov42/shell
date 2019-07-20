/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:26:34 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:38:55 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/environment.h"
#include "shell.h"
#include "utils/shell_utils.h"
#include "utils/environment_utils.h"
#include "libft.h"

char	*get_environment(char *name)
{
	int		i;
	char	*value;
	char	**split;

	if (!variable_is_valid(name))
	{
		return (NULL);
	}
	i = 0;
	value = NULL;
	while (g_shell.env[i])
	{
		if (ft_strncmp(g_shell.env[i], name, ft_strlen(name)) == 0)
		{
			split = ft_strsplit(g_shell.env[i], '=');
			value = ft_strdup(split[1]);
			ft_splitdel(&split);
			break ;
		}
		++i;
	}
	return (value);
}

int		set_environment(char *key, char *value)
{
	int		i;
	char	*curr_env;

	if (!(curr_env = get_environment(key)))
	{
		g_shell.env = ft_append_to_split(
			g_shell.env,
			ft_strs_join_c(key, value, '='));
		return (SUCCESS);
	}
	i = 0;
	while (g_shell.env[i])
	{
		if (ft_strncmp(key, g_shell.env[i], ft_strlen(key)) == 0)
		{
			free(g_shell.env[i]);
			g_shell.env[i] = ft_strs_join_c(key, value, '=');
		}
		++i;
	}
	safe_free(curr_env);
	return (SUCCESS);
}

int		unset_environment(char *name)
{
	char	**env_array;
	char	*curr_env_var;

	if (!(curr_env_var = get_environment(name)))
	{
		return (NO_SUCH_ENV);
	}
	env_array = ft_remove_from_split(g_shell.env, name);
	safe_free(g_shell.env);
	safe_free(curr_env_var);
	g_shell.env = env_array;
	return (SUCCESS);
}

char	**copy_environment(char **argenv, char **globalenv)
{
	int		i;
	char	**cpy;
	char	**env;

	env = argenv ? argenv : globalenv;
	cpy = (char **)ft_memalloc(sizeof(char *) *
		(ft_strsplit_count((const char **)env) + 1));
	i = -1;
	while (env[++i])
	{
		cpy[i] = ft_strdup(env[i]);
	}
	return (cpy);
}
