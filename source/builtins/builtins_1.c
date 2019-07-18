#include "builtins/builtins.h"
#include "utils/shell_utils.h"
#include "libft.h"

int	bt_echo(char **args)
{
	char	*str;
	char	*result;

	if (!args || !args[0])
	{
		ft_printf('\n');
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

int	bt_cd(char **args)
{

	return (SUCCESS);
}

int	bt_setenv(char **args)
{

	return (SUCCESS);
}

int	bt_unsetenv(char **args)
{

	return (SUCCESS);
}

int	bt_env(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		ft_printf("%s\n", args[i]);
		++i;
	}
	return (SUCCESS);
}
