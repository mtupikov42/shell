#include "environment/environment.h"

#include "utils/shell_utils.h"

int		set_environment(char *key, char *value)
{

	return (SUCCESS);
}

int		unset_environment(char *name)
{

	return (SUCCESS);
}

char	*get_environment(char *name)
{

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
