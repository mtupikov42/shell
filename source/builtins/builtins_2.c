#include "builtins/builtins.h"
#include "utils/shell_utils.h"
#include "libft.h"

int	bt_exit(char **)
{
	return (EXIT_REQUEST);
}

int	bt_help(char **)
{
	int		i;

	ft_printf("These builtins are avaiable:\n");
	i = 0;
	while (i < 7)
	{
		ft_printf(" %i) %s\n", i, g_builtins_names[i]);
		++i;
	}
	return (SUCCESS);
}