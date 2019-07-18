#include "environment/environment.h"

#include "shell.h"
#include "utils/shell_utils.h"
#include "utils/environment_utils.h"

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
	while (g_shell.env[i])
	{
		if (!ft_strncmp(name, g_shell.env[i], ft_strlen(name)))
		{
			split = ft_strsplit(g_shell.env[i], '=');
			value = ft_strdup(split[1]);
			ft_splitdel(&split);
			break;
		}
		++i;
	}
	return (value ? value : ft_strnew(0));
}

int		set_environment(char *key, char *value)
{
	int		i;
	char	**split;
	char	*curr_env;

	if (!(curr_env = get_environment(key)))
	{
		ft_append_to_split(g_shell.env, ft_strs_join_c(key, value, '='));
	}
	i = 0;
	while (g_shell.env[i])
	{
		if (!ft_strncmp(key, g_shell.env[i], ft_strlen(key)))
		{
			split = ft_strsplit(g_shell.env[i], '=');
			free(g_shell.env[i]);
			g_shell.env[i] = ft_strs_join_c(key, value, '=');
			ft_splitdel(split);
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
	cpy = (char **)ft_memalloc(sizeof(char*) * ft_strsplit_count(env));
	i = -1;
	while (env[++i])
	{
		cpy[i] = ft_strdup(env[i]);
	}
	return (cpy);
}
